cmake_minimum_required(VERSION 3.15)
project(lab07_2019102096)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp UnsortedList.cpp UnsortedList.h SortedList.cpp SortedList.h CircularQueue.cpp CircularQueue.h SingleLinkedList.cpp SingleLinkedList.h ItemType.cpp ItemType.h SimpleItemType.cpp SimpleItemType.h ContainerType.cpp ContainerType.h StorageType.cpp StorageType.h TempType.cpp TempType.h Application.cpp Application.h UserType.cpp UserType.h BinarySearchTree.cpp BinarySearchTree.h CHeapBase.cpp CHeapBase.h CMinHeap.cpp CMinHeap.h)
