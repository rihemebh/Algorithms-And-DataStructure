# Algorithms and DataStructure

[Still working on it and open to any contribution]

## Algorithms 
### What is an Algorithm ? 
If you are new in this field I advise you to check this article to better understand what is algorithms and the algorithmic thinking.
https://medium.com/@rihmebenhassan/entering-the-algorithms-maze-252e7b0afa40

### Types: 

<!--### Recursive 
#### What is recursion 

#### How it works
### Greedy 
### Branch and Bound 
### Dynammic Programming -->
### Divide & Conquer
Divide and conquer isan algorithmic paradigm  consists of two main parts: <br/>
1. Divide the problem into smaller subproblems of the same type, and solve these subproblems recursively
2. Combine the solutions to the subproblems into a solution to the original problem

A very known example is the Merge sort 

if you want to sort an array you can divide it into n arrays sort them and then merge with sort 

<!--### Brute force 
-->

## Data structure 
<!--### What is Data structure 
### Array
### Stack and Queue 
### Hash table 
### Binary Tree
### AVL Tree-->
### Heap  

 A heap is a perfect tree 
 
 Every node should has a priority lower than its two children  


- ***Insert***

 1. Add the element at the end of the tree 
 2. Compare its priority with its father's priority
 3. Switch places if the father has the highest priority

- ***Delete Element***
```
Keep in mind that the heap is made to help us retrieve the element with the lowest priority easly which is the root node 
Actually this is the only delete case we need.  
```
1. Put the last element in the node 
2. Swap the node with the lowest priority of its two sons 
3. Repeat this algo until we have the right structure of the heap 

[Click Me to see the code](https://github.com/rihemebh/algorithms-and-data-structure/blob/main/heap/main.cpp)

### B-tree

A N-2N btree has :

- Sorted keys 
- The root node should has at least one key 
- Nodes have At least N-1 keys 
- All nodes have At most 2*N-1 keys
- The number of children = number of keys + 1 

We have to ensure that our btree doesn't break these rules while inserting or deleting.

#### ***Insert a key***

#### NOTE:
```
In a B-ree we could only insert in a leaf 
In every Node we should find the child that has keys less than the key to be inserted until the current node is a leaf.
If this child has 2*N-1 we should split it.
```

- Split a node means :
    - Find the median key ( key[N-1] )
    - Add this median to the father
    - Add the keys after the median to a new node and link it to the father

- And we have 2 cases : 
    - Split in a simple node  (internal or leaf)
        1. If the node is a leaf we add the new key to it 
        2. If it is internal: 
            2.1. Find the next node 
            2.2. If the child has 2*N-1 keys then split it 
    - Split in a Root node 
        1. If the Root already has 2*N-1 keys : create a new node and call split(newnode,0)
        2. The same algo as a simple node 
    

       
#### ***Delete a key***

Unlike the insert process we could delete a key from any node   
So to ensure that our btree doesn't break any rule we have an alternative to each case : 

- **Borrow key** : 
    ```
    If we want to delete from an leaf that has exactly N-1 keys and one of the siblings has N or more Keys
    
    ```

- **Fusion 2 siblings**
    ```
    1. If we want to delete from an internal node and the 2 children have N-1 keys
    2. If the next node has N-1 keys and the same for its siblings 
    ```
- **Replace with pred or succ**
    ```
     If we want to delete from an internal node and its children aren't leafs 
    ```
    
   

[Click Me to see the code](https://github.com/rihemebh/algorithms-and-data-structure/blob/main/btree/main.cpp)




<!--### How to chose the right Data structure for your code -->





