'''
Author       : Outsider
Date         : 2023-06-26 11:44:43
LastEditors  : Outsider
LastEditTime : 2023-06-26 12:15:35
Description  : In User Settings Edit
FilePath     : \Lq\other\net-change.py
'''
# encoding: utf-8

import time
import math
import os
from threading import Timer
from datetime import datetime
import json
import base64
import httplib

import random

time_start = time.time()

def flow_put(switch_id,port):

    try:
        #---------------------------------------------------s1-------------------------------------------------------       
        #url
        url = "/restconf/config/opendaylight-inventory:nodes/node/" + switch_id + "/flow-node-inventory:table/0/flow/1"     
        flow_set = {
        'id': '1',
        'flow-name': '1',
        'table_id': 0,
        'priority': "200"
        }

        #match
        match_set = {'in-port':switch_id+':1'}

        #action
        action_set = {
        'order': "0",
        'output-action':{"output-node-connector": switch_id +':' + port }
        }
        instruc_set = {
            "instruction": [{
                "order": "0",
                "apply-actions": {
                    "action": [action_set]
                }
            }]
        }

        flow_set['match'] = match_set
        flow_set['instructions'] = instruc_set
        body = json.dumps({"flow":flow_set})
        auth = base64.b64encode('admin:admin'.encode())
        headers = {"Authorization": "Basic " + auth,"Content-Type": "application/json"}

        conn = httplib.HTTPConnection('127.0.0.1:8181', timeout=3)
        conn.request("PUT", url, body, headers)

        response = conn.getresponse()
        ret = response.read()

        if response.status not in [200,201]:
            # print 'add flow error!'
            #  print(switch_id,port)
            pass

        #------------------------------------------s1 port2--->port1-------------------------------------------------       
        url_out = "/restconf/config/opendaylight-inventory:nodes/node/" + switch_id + "/flow-node-inventory:table/0/flow/2" 
        flow_set['id'] = 2
        flow_set['flow-name'] = '2'
        flow_set['match']['in-port'] = switch_id + ':' + port

        action = flow_set['instructions']['instruction'][0]['apply-actions']
        action['action'][0]['output-action']['output-node-connector'] = switch_id + ':1'
        body_out = json.dumps({"flow":flow_set})

        conn.request("PUT", url_out, body_out, headers)
        response = conn.getresponse()
        ret = response.read()


    except Exception as e:
        pass

def flow_delete(switch_id):

    url_in = "/restconf/config/opendaylight-inventory:nodes/node/" + switch_id + "/flow-node-inventory:table/0/flow/1"      
    url_out = "/restconf/config/opendaylight-inventory:nodes/node/" + switch_id + "/flow-node-inventory:table/0/flow/2"     
    auth = base64.b64encode('admin:admin'.encode())
    headers = {"Authorization": "Basic " + auth, "Content-Type": "application/json"}

    conn = httplib.HTTPConnection('127.0.0.1:8181', timeout=3)
    try:
        conn.request("DELETE", url_in, json.dumps({}), headers)
        conn.request("DELETE", url_out, json.dumps({}), headers)
    except:
        pass


def flow_change(s1_node_id,s5_node_id,s4_node_id):

    time_now = time.time()      #当前的时间
    time_interval = time_now - time_start  #和开始的时间的时差
    interval_num = time_interval // 30        #整除30
    port_flag = math.floor(interval_num%3)   #取余3

    rint=random.randint(0,1) #随机数用于选择s4端口
    
    if port_flag == 0:
            port = '2'
    elif port_flag == 1:
            port = '3'
    elif port_flag ==2 :
        port = '4'
        # s4选择端口
        if rint==0:
                s4_port='2'
        else:
                s4_port='3'

    #先清空流表再下发，避免多次下发相同id的流表到ODL，ODL不主动下发到交换机
    flow_delete(s1_node_id)
    flow_put(s1_node_id,port)

    if port=='4' and s4_port=='3': # s1->s4->s6的路径
        flow_delete(s4_node_id)
        flow_put(s4_node_id,s4_port)
        #cmd="ovs-ofctl add-flow s4 in_port=1,actions=output:"+s4_port
        #print(cmd)
        #os.system(cmd)
    else: # 为 s4 和 s5 添加流表
        flow_delete(s5_node_id)
        flow_put(s5_node_id,port)
        flow_delete(s4_node_id)
        flow_put(s4_node_id,'2')

    if port!='4' or (port=='4' and s4_port=='2'):
        print 'route is : s1 --> s%s --> s5' % port
    else:
        print 'route is : s1 --> s%s --> s6' % port
    t = Timer(5,flow_change,(s1_node_id,s5_node_id,s4_node_id))
    t.start()

if __name__ ==  '__main__':

    # s1_node_id = raw_input('s1 交换机 node—id：')
    # s5_node_id = raw_input('s5 交换机 node—id：')

    s1_node_id = 'openflow:1'
    s5_node_id = 'openflow:5'
    s4_node_id = 'openflow:4'
    flow_put(s1_node_id,'2')
    flow_put(s5_node_id,'2')

    flow_change(s1_node_id,s5_node_id,s4_node_id)
