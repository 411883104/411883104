from mininet.net import Mininet
from mininet.cli import CLI
from mininet.node import RemoteController ,Controller
import os

net=Mininet(controller=RemoteController)
odl_controller=net.addController('ODL_controller',controller= RemoteController,ip='30.0.1.3',port=6653)
# 添加交换机 s1,s2,s3,s4,s5,s6
s1=net.addSwitch('s1')
s2=net.addSwitch('s2')
s3=net.addSwitch('s3')
s4=net.addSwitch('s4')
s5=net.addSwitch('s5')
s6=net.addSwitch('s6')
# 添加主机 h1,h2
h1=net.addHost('h1')
h2=net.addHost('h2')

# 添加链路

net.addLink(s1,h1)

net.addLink(s5,h2)

net.addLink(s6,h2)

net.addLink(s1,s2)
net.addLink(s1,s3)