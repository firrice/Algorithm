//练手shared_ptr指针的定义：
template<typename Dtype>
class WPtr{
	typedef Dtype* Dtype_ptr;

	template<class T>
	struct ptr_info  //智能指针的结构体
	{
		T p;  //智能指针
		int ref_count;  //引用计数
		ptr_info(T p) : T(p), ref_count(1){}
		void add_ref(){ ref_count++; }
		bool release_ref(){ return --ref_count <= 0; }
	};
public:
	WPtr() :ptr(0){}  //第一种初始化函数：直接产生一个空的智能指针结构体指针
	WPtr(Dtype_ptr p)  //第二种初始化函数：产生一个智能指针指向一块参数p指向的堆内存
	{
		ptr = new ptr_info<Dtype_ptr>(p);
	}
	WPtr(const WPtr& other):ptr(0)  //第三种初始化函数：从已有的智能指针来赋值给一个新的智能指针
	{
		operator=(other);
	}
	~WPtr()  //析构
	{
		releaseRef();
	}

	Dtype_ptr get()  //这么操作是为了加上return 0这个，弥补原生->操作的不足
	{
		if (this->ptr)
			return ptr->ptr;
		return 0;
	}

	Dtype_ptr operator Dtype_ptr()
	{
		return get();
	}

	Dtype_ptr operator->()
	{
		return get();
	}

	void addRef()
	{
		if (this->ptr)
			this->ptr->add_ref();
	}

	WPtr& operator=(const WPtr& other)
	{
		releaseRef();

		this->ptr = other.ptr;
		addRef();
		return *this;	
	}

	void relase(Dtype_ptr p);

	void releaseRef()
	{
		if (this->ptr && this->ptr->release_ref())  //如果该智能指针之前指向的堆内存引用计数为1，由于该指针指向其他地方则释放掉原先这块内存，如果引用计数大于1，则减一即可
		{
			release(this->ptr->ptr);
			delete(ptr);
			ptr = NULL;
		}
	}
private:
	ptr_info<Dtype_ptr> *ptr;
};

template<typename Dtype>
void WPtr::release(Dtype_ptr p)
{
	if (p)
		delete p;
}
