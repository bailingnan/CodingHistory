const int maxn = 100;
int heap[maxn], n = 10;
//对heap数组在[low,high]范围进行向下调整
//其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high) {
	int i = low, j = i * 2;//i为欲调整结点，j为其左孩子
	while (j <= high) {//存在孩子结点
		//如果右孩子存在，且右孩子的值大于左孩子
		if (j + 1 <= high && heap[j + 1] > heap[j]) {
			j = j + 1;//让j存储右孩子下标
		}
		//如果孩子中最大的权值比欲调整结点i大
		if (heap[j] > heap[i]) {
			swap(heap[i], heap[j]);
			i = j;
			j = i * 2;
		}
		else {
			break;
		}
	}
}
//建堆,时间复杂度O(n)
void createHeap() {
	for (int i = n / 2; i >= 1; i++) {
		downAdjust(i, n);
	}
}
//删除堆顶元素，时间复杂度O(logn)
void deleteTop() {
	heap[1] = heap[n--];//用最后一个元素覆盖堆顶元素，并让元素个数减1
	downAdjust(1, n);//向下调整堆顶元素
}
//对heap数组在[low,high]范围内向上调整
//其中low一般设置为1，high表示欲调整结点的数组下标
void upAdjust(int low, int high) {
	int i = high, j = i / 2;//i为欲调整结点，j为其父亲
	while (j >= low) {//父亲在[low,high]范围内
		//父亲权值小于欲调整结点i的权值
		if (heap[j] < heap[i]) {
			swap(heap[j], heap[i]);//交换父亲和欲调整结点
			i = j;
			j = i / 2;
		}
		else {
			break;//父亲权值比欲调整结点i的权值大，调整结束
		}
	}
}
//添加元素x
void insert(int x) {
	heap[++n] = x;//让元素个数加1，然后将数组末位赋值为x
	upAdjust(1, n);//向上调整新加入的结点n
}
//堆排序
void heapSort() {
	createHeap();//建堆
	for (int i = n; i > 1; i--) {//倒着枚举，直到堆中只有一个元素
		swap(heap[i], heap[1]);//交换heap[i]与堆顶
		downAdjust(1, i - 1);//调整堆顶
	}
}
