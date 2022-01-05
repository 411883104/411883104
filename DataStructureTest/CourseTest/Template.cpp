
/**
 * @description: 
 * 定义一个优先队列，内部使用动态分配内存实现数组存数
 */

template<Class T>
class MaxHeap{
private:
    /**
     * @description: 私有成员变量定义
     * @param arr 数组首地址
     * @param length 数组已存元素长度
     * @param max_length 数组最大存储长度
     */
    int* arr;
    int length;
    int max_length;

public:
    /**
     * @description: 公有成员函数定
    */
    MaxHeap();

    /**
     * @description:重载运算符[] 
     * @param {*}
     * @return {*}
     */
    int& operator[](int i){
        return *(this->arr+i);
    }

    /**
     * @description: 返回数组已存元素长度 
     * @param {*}
     * @return {*}
     */    
    int size(){
        return length;
    }

    void resize();
    void push_back(int);
    void pop_back();
    void Sink(int k,T fun);
    void Float(int);
    int& top();
};

/**
 * @description: 节点下沉
 * @param {int} k 节点的下标
 * @return {*}
 */
void MaxHeap::Sink(int k,T fun)//将小的节点下沉
{
    while (2 * k + 1 < length) {  //2*k为左孩子，2*k+1为右孩子,有左孩子则循环
        int j = 2 * k + 1; //如果数组从0开始，则2K+1为左孩子，2K+2为右孩子
        if (j + 1 < length && fun(arr[j],arr[j + 1])) {//如果有右孩子且右孩子比左孩子大
            j++;
        }
        if (arr[k] >= arr[j]) {     //父节点比较大的孩子节点大，则已满足堆
            break;
        }
        else {
            //交换
            int temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
        }
        k = j;//往下比较，一直下沉到叶子
    }
}

void MaxHeap::Float(int k)
{
    while(k>0){ //如果当前节点的值比父节点大，则节点上浮
        int j=(k-1)/2;       //父节点下标
        if(arr[k]>arr[j]){
            //交换值
            int temp=arr[k];
            arr[k]=arr[j];
            arr[j]=temp;
        }
        k=j;  //继续往堆顶访问下去
    }
}

MaxHeap::MaxHeap()
{
    length=0;
    max_length=100;
    arr=new int[max_length];
}

/**
 * @description: 数组长度不够，重新分配空间
 * @param size 数组长度
 * @return {*}
 */
void MaxHeap::resize()
{
    int* new_arr=new int[2*(max_length)];
    for(int i=0;i<max_length;i++){
        new_arr[i]=arr[i];
    }
    delete []this->arr;
    this->arr=new_arr;
    this->max_length=2*(this->max_length);
}

/**
 * @description: 向数组中加入元素
 * @param {int} num 待加入数值
 * @return {*}
 */
void MaxHeap::push_back(int num)
{
    if(length<max_length){
        arr[length++]=num;
        Float(length-1);
    }
    else{
        //扩容
        resize();
        push_back(num);
    }
}


void MaxHeap::pop_back()
{
    int temp=arr[0];
    arr[0]=arr[--length];
    arr[length]=temp;
    Sink(0);
}

/**
 * @description: 获取堆顶元素
 * @param {*}
 * @return {*} 堆顶元素
 */
int& MaxHeap::top()
{
    return *(this->arr);
}

int main()
{
    MaxHeap<bool*>
}