#ifndef STACK
#define STACK
#include <cstddef>

using ItemT = int;

struct StackNodeT;

struct StackNodeT {
	ItemT data;
	StackNodeT* link;
};

class StackT {
   public:
       StackT();
       StackT(const StackT&);

       ~StackT();
       StackT& operator=(const StackT&);

       StackT(StackT&&) noexcept;
       StackT& operator=(StackT&& rhs) noexcept;

       void Push(ItemT);
       void Pop();
       ItemT Top() const;

       std::size_t Size() const;

       bool IsEmpty() const;

   private:
        StackNodeT* stack;
        std::size_t size;
};

#endif