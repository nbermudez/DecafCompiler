#define MAX_DEEP_NESTING 3

class Context {
public:
	Context();
	Context *previous;

	int offset = 0;
};

class ContextManager {
public:
	static ContextManager& getInstance() {
        static ContextManager instance;
        return instance;
    }

    void registerContext(int level, Context * context);
    void unregisterContext(int level);

private:
	ContextManager();
	Context* display[MAX_DEEP_NESTING];
};