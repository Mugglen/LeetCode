

//#define DEBUG
#ifdef DEBUG

class Singleton {

private:
	static Singleton* instance;
	// 私有构造函数
	Singleton() {}
	~Singleton() {}

public:
	// 静态函数初始化
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}

};

// 静态成员变量初始化
Singleton* Singleton::instance = nullptr;



#endif // DEBUG
