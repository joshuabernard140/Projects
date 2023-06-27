#include <cstdlib>
#include <iostream>

//Joshua Bernard U92651625
//Raiyan Ali U24491765
//This program checks if an equation has an equal amount of left and right parenthesis

//class that is used for each node of the stack and holds the parenthesis
class node{

	public:
    	char character;
    	node* next;

    	node(char parenthesis){
    	    character = parenthesis;
    	    next = nullptr;
    	}
};

//class used as stack for linked list
class stack{

	public:
		node* head;

    	stack(){
    	    head = nullptr;
    	}

		//function that pushes parenthesis to the stack
    	void push(char parenthesis){
    	    node* newNode = new node(parenthesis);

			//checks if stack is empty or not to determine where to push
    	    if (head == nullptr){
    	        head = newNode;
    	    }else{
    	        node* current = head;
    	        while (current->next != nullptr){
    	            current = current->next;
    	        }
    	        current->next = newNode;
    	    }
    	    //std::cout << parenthesis << " pushed to the list\n";
    	}

		//function that pops a parenthesis from the stack
    	bool pop(bool checkEmpty){
			//checks if list is empty
    	    if (head == nullptr){
    	        //std::cout << "List is empty\n";
				checkEmpty = true;
    	        return checkEmpty;
    	    }

    	    node* current = head;
    	    node* previous = nullptr;
    	    while (current->next != nullptr){
    	        previous = current;
    	        current = current->next;
    	    }

     	   if (previous != nullptr){
    	        previous->next = nullptr;
    	    }else{
    	        head = nullptr;
    	    }

    	    //std::cout << current->character << " popped from the list\n";
    	    delete current;
    	}

		//no-op function
		void no_op(){
			return;
		}
};

//checks if an equation has an equal amount of left and right parenthesis
bool equationCheck(stack list, std::string equation){

	bool checkFinal = true;
	bool checkEmpty = false;
	int i;

	//checks if ( and ) are equal
	for (i = 0; equation[i] != '\0'; i++){
		if (equation[i] == '('){
			list.push(equation[i]);
		}
		if (equation[i] == ')'){
			checkEmpty = list.pop(checkEmpty);
			if (checkEmpty == true){
				return false;
			}
		}
	}
	if (list.head != '\0'){
		return false;
	}

	//checks if { and } are equal
	for (i = 0; equation[i] != '\0'; i++){
		if (equation[i] == '{'){
			list.push(equation[i]);
		}
		if (equation[i] == '}'){
			checkEmpty = list.pop(checkEmpty);
			if (checkEmpty == true){
				return false;
			}
		}
	}
	if (list.head != '\0'){
		return false;
	}

	//checks if [ and ] are equal
	for (i = 0; equation[i] != '\0'; i++){
		if (equation[i] == '['){
			list.push(equation[i]);
		}
		if (equation[i] == ']'){
			checkEmpty = list.pop(checkEmpty);
			if (checkEmpty == true){
				return false;
			}
		}
	}
	if (list.head != '\0'){
		return false;
	}

	//checks if < and > are equal
	for (i = 0; equation[i] != '\0'; i++){
		if (equation[i] == '<'){
			list.push(equation[i]);
		}
		if (equation[i] == '>'){
			checkEmpty = list.pop(checkEmpty);
			if (checkEmpty == true){
				return false;
			}
		}
	}
	if (list.head != '\0'){
		return false;
	}

	//checks if stack is empty
	if (list.head != nullptr){
		checkFinal = false;
	}
	return checkFinal;
}

//main function
int main(){

	stack list;
	bool check;

	//test cases
	check = equationCheck(list, "{{{{}}}[][]((())");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "(%TT{>><]]]%%%%%%)");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "(((((()))))){}{}{}[][][][[[]]]");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "{{{@23+6767}}}*<45>(a+b)[]");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "(a+b)");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "(((((a+b %%%%%####3422222222222)))))[]{}[]");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "[[[{{()}}]]]");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "((((((}}}}}}");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$)");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}
	check = equationCheck(list, "@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
	if (check == 1){
		std::cout << "True\n";
	}else{
		std::cout << "False\n";
	}

	/*{{{{}}}[][]((()) False
	(%TT{>><]]]%%%%%%) False
	(((((()))))){}{}{}[][][][[[]]] True
	{{{@23+6767}}}*<45>(a+b)[] True
	(a+b) True
	(((((a+b %%%%%####3422222222222)))))[]{}[] True
	[[[{{()}}]]] True
	((((((}}}}}} False
	Aaaaaaaa+bbbb({}{}{}[][][]tttttt + %^$) True
	@@@@@@@@@@@@@@@@@@@@@@@$$%%T$%$%$$%{}()%%%%%%%%%%%%%%%%%%%%%%%%%%%% True*/

	return 0;
}