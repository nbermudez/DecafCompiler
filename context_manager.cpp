#include "context_manager.h"

ContextManager::ContextManager() {
	for (int i = 0; i < MAX_DEEP_NESTING; i++) {
		display[i] = NULL;
	}
}

void ContextManager::registerContext(int level, Context* context) {
	context->previous = display[level];
	display[level] = context;
}

void ContextManager::unregisterContext(int level) {
	if (display[level] != NULL)
		display[level] = display[level]->previous;
}