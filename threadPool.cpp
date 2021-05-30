
#define LL_INSERT(item,list) do{#item是一个事件,list是执行队列
	item->prev=null;
	item->next=list;
	list->prev=item;
	list=item;
} while(0)

#define LL_REMOVE(item,list)do{
	if(item->prev==null) item->prev->next=item->next;
	if(item->next!=null) item->next->prev=item->prev;
	if(list==item) list=item->next;
	item->prev=item->next=null;
}while(0)

struct NJOB{
	void (*job_fun)(void *arg);#回调函数
	void *user_data;
	struct NJOB *prev;#工作队列上一个任务节点
	struct NJOB *next;#工作队列下一个任务节点
}

struct NWORKER{
	pthread_t thread;#当前线程ID
	struct NWORKER *prev;#指向链表上一个工作线程的指针
	struct NWORKER *next;#指向链表下一个工作线程的指针
}

struct NTHREADPOOL{
	struct NWORKER *nworkers;#工作队列的链表
	struct NJOB *jobs;#任务队列的链表
	pthread_mutex_t mutex;#线程锁
	pthread_cond_t cond;#条件变量
}

int ntyThreadPoolCreate
