
class Singleton {
private:
	Singleton();
public:
	Singleton(Singleton & copySingleton) = delete;
	void operator=(const Singleton &) = delete;

	static Singleton & get();
};