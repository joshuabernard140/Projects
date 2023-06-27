#include <cstdlib>
#include <iostream>

//Joshua Bernard U92651625
//Raiyan Ali U24491765
//This program creates a queue with the functions push, pop, empty, size, front, and back

//class for the queue
class array{

    public:
        //variables
        int storage[500];
        int start;
        int end;
        bool checkEmpty = true;

        array(){
            start = 0;
            end = 0;
        }

        //pushes an element to the end of the queue
        void push(int element){
            if (end == -1){
                end = 0;
            }
            if (checkEmpty == true){
                storage[0] = element;
                checkEmpty = false;
            }else{
                end++;
                end = end % 500;
                storage[end] = element;
            }
        }

        //removes an element from the beginning of the queue unless queue is empty
        void pop(){
            if (end == -1) {
                std::cout << "Array is empty\n";
                return;
            }
            for (int i = 0; i < end; i++) {
                storage[i] = storage[i + 1];
            }
            end--;
            if (end == -1){
                checkEmpty = true;
            }
        }

        //checks if queue is empty
        void empty(){
            if (checkEmpty == true){
		        std::cout << "True\n";
	        }else{
		        std::cout << "False\n";
	        }
        }

        //checks how many elements are in the queue
        void size(){
            if (checkEmpty == true){
                std::cout << "The queue has 0 elements\n";
                return;
            }else if (end == 0){
                std::cout << "The queue has 1 element\n";
                return;
            }else{
                std::cout << "The queue has " << end + 1 << " elements\n";
            }
        }

        //prints the first element in the queue unless queue is empty
        void front(){
            if (checkEmpty == true){
		        std::cout << "Queue is empty\n";
                return;
            }
            std::cout << storage[start] << "\n";
        }

        //prints the last element in the queue unless queue is empty
        void back(){
            if (checkEmpty == true){
		        std::cout << "Queue is empty\n";
                return;
            }
            std::cout << storage[end] << "\n";
        }

        //not needed but prints all elements in queue (used for testing)
        void print(){
            for (int i = start; i <= end; i++){
                std::cout << storage[i] << "\n";
            }
        }

};

//main function
int main(){

    array Queue = array();

    //test cases
    Queue.push(5);
    Queue.push(8);
    Queue.push(4);
    Queue.push(2);
    Queue.front(); //5 
    Queue.pop();
    Queue.front(); //8
    Queue.pop();
    Queue.front(); //4 
    Queue.pop();
    Queue.front(); //2 
    Queue.back(); //2 
    Queue.empty(); //False 
    Queue.pop();
    Queue.empty(); //True 
    Queue.size(); //0

    return 0;
}