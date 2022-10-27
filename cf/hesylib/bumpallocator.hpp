#ifndef HESY_BUMPALLOCATOR_HPP
#define HESY_BUMPALLOCATOR_HPP 1
// Either globally or in a single class:
static char buf[450 << 20];  // 450MB 
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

#endif // HESY_BUMPALLOCATOR_HPP
