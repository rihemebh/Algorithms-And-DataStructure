# algorithms-and-data-structure

## Algorithms 

## Data structure 

### Hash table 
### AVL 
### Heap  

- A heap is a perfect tree 
- Every node shoud have a priority lower than their two sons priority 


- ***Insert***

 1. Add the element at the end of the tree 
 2. Compare hsi priority with his father's priority
 3. Switch places if the father has the highest priority

- ***Delete Element***
```
Keep in mind that the heap is made to help us retrieve the element with the lowest priority easly which is the root node , actually this is the only delete case we need.  
```
1. Put the last element in the node 
2. Swap the node with the lowest priority of its two sons 
3. Repeat this algo until we have the right structure of the heap 

[Click Me to see the code]()

### B-tree

