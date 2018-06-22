//����shared_ptrָ��Ķ��壺
template<typename Dtype>
class WPtr{
	typedef Dtype* Dtype_ptr;

	template<class T>
	struct ptr_info  //����ָ��Ľṹ��
	{
		T p;  //����ָ��
		int ref_count;  //���ü���
		ptr_info(T p) : T(p), ref_count(1){}
		void add_ref(){ ref_count++; }
		bool release_ref(){ return --ref_count <= 0; }
	};
public:
	WPtr() :ptr(0){}  //��һ�ֳ�ʼ��������ֱ�Ӳ���һ���յ�����ָ��ṹ��ָ��
	WPtr(Dtype_ptr p)  //�ڶ��ֳ�ʼ������������һ������ָ��ָ��һ�����pָ��Ķ��ڴ�
	{
		ptr = new ptr_info<Dtype_ptr>(p);
	}
	WPtr(const WPtr& other):ptr(0)  //�����ֳ�ʼ�������������е�����ָ������ֵ��һ���µ�����ָ��
	{
		operator=(other);
	}
	~WPtr()  //����
	{
		releaseRef();
	}

	Dtype_ptr get()  //��ô������Ϊ�˼���return 0������ֲ�ԭ��->�����Ĳ���
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
		if (this->ptr && this->ptr->release_ref())  //���������ָ��֮ǰָ��Ķ��ڴ����ü���Ϊ1�����ڸ�ָ��ָ�������ط����ͷŵ�ԭ������ڴ棬������ü�������1�����һ����
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
