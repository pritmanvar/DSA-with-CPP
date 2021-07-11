<h1></h1>
<h1> Advantages of Linked Lists </h1>
<p>The advantage of linked lists is that they can be expanded in constant time. To create an array, we must allocate memory for a certain number
of elements. To add more elements to the array when full, we must create a new array and copy
the old array into the new array. This can take a lot of time.
</p>

<p>We can prevent this by allocating lots of space initially but then we might allocate more than we
need and waste memory. With a linked list, we can start with space for just one allocated element
and add on new elements easily without the need to do any copying and reallocating.
</p>

<br>

<h1></h1>
<h1> disadvantages of Linked Lists </h1>
<p>The main disadvantage of linked lists is access time to individual elements. Array is 
random-access, which means it takes O(1) to access any
element in the array. Linked lists take O(n) for access to an element in the list in the worst case.
Another advantage of arrays in access time is spacial locality in memory. Arrays are defined as
contiguous blocks of memory, and so any array element will be physically near its neighbors. This
greatly benefits from modern CPU caching methods
</p>

<p>Although the dynamic allocation of storage is a great advantage, the overhead with storing and
retrieving data can make a big difference. Sometimes linked lists are hard to manipulate. If the
last item is deleted, the last but one must then have its pointer changed to hold a NULL reference.
This requires that the list is traversed to find the last but one link, and its pointer set to a NULL
reference
</p>

# 
# Comparison of Linked Lists with Arrays & Dynamic Arrays
| Parameter | Linked List | Array | Dynamic Array |
| --- | --- | --- | --- |
| `Indexing` | `O(n)` | `O(1)` | `O(1)` |
| `Insertion or Deletion at beginning` | `O(1)` | `O(n)  if array is not full` | `O(n)` |
| `Insertion at ending` | `O(n)` | `O(1) if array is not full`| `O(1) if array is not full` `O(n)if array is full` |
| `Deletion at ending` | `O(n)` | `O(1)` | `O(n)` |
| `Insertion at middle` | `O(n)` | `O(n)  if array is not full` | `O(n)` |
| `Deletion at middle` | `O(n)` | `O(n)  if array is not full` | `O(n)` |
| `Wasted Space` | `O(n) for pointers` | `0` | `O(n)` | 
