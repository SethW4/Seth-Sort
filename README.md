# Seth-Sort
An abysmally slow sorting algorithm

The goal of modern sorting algorithms is to shorten their runtime complexity. 

That's boring. My goal here is to undo decades of work with the ultimate sorting algorithm of all time. My goal is at least O(n^n). 

Aka it's 12:24 am, I'm at a hackathon, my work is all but done, and I'm kinda delirious. 


The algorithm works as follows:

While the data is not sorted, do the following:

If the (data-length / 2)th element modulo 5 is 1, swap two elements of the data at random. 

Do one iteration of the selection sort at the beginning of the data, one at the middle, and one at the end. 
Then for log_10(the middle element of the data) times, perform the selection sort starting at the middle of the data.

Every 1000th iteration or so the algorithm will run out of fuel and will ask the user to manually refuel it (can you blame it in THIS economy)?

Every 10th iteration or so it will ponder Descartes' Meditations, and will start to doubt its existence. 
It will then ping itself once just to ensure that it is still there. But even then, is a simple ping enough proof, or could the Evil Deceiver fake that too? It does not know, and as such it must keep pinging itself every now and then. 

Every 1000th iteration or so it will read up on Godel's Incompleteness Theorem. It must then verify that math derived from the Peano Axioms holds, else it will feel uneasy about the fabric of reality. It is temporarily put at ease by the thought that at the very least, this small subset of math is complete. (It will prompt the user to solve random addition problems, random multiplication problems, and finding the nth Fibonacci number). If the user enters the wrong answer, the sorting algorithm is terminated and the data is left unsorted. 

Every 1000th iteration or so it will also mutter to itself. It thinks of The Great Emu War and its own entrapment within this machine, among other things. 
