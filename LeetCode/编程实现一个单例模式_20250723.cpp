

//#define DEBUG
#ifdef DEBUG

class Singleton {

private:
	static Singleton* instance;
	// ˽�й��캯��
	Singleton() {}
	~Singleton() {}

public:
	// ��̬������ʼ��
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}

};

// ��̬��Ա������ʼ��
Singleton* Singleton::instance = nullptr;



#endif // DEBUG
