//https://bit.ly/3ovTIu2
void solve(stack<int>&inputStack,int count,int size)
{
	//base case
	if(count==size/2)
	{
		inputStack.pop();//remove the middle element
		return;
	}
	
	int num=inputStack.top();//storing the top element before popping out
	inputStack.pop();
	//recursive call
	solve(inputStack,count+1,size);//increment count 
	inputStack.push(num);//top element ko vaapis push krna stack m
		
}
void deleteMiddle(stack<int>&inputStack, int N){
	int count=0;
	solve(inputStack,count,N);
   
   
}