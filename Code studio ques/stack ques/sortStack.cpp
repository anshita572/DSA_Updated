//https://bit.ly/3snpr1B
//TC : O(n^2)
void insertSorted(stack<int> &stack,int element)
{
	//base case
	if(stack.empty() || stack.top()<element)
	{
		stack.push(element);
		return;
	}
	int num=stack.top();
	stack.pop();
	
	insertSorted(stack,element); //recursive call
	stack.push(num);
}
void sortStack(stack<int> &stack)
{
   //base case
	if(stack.empty())
	{
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);//recursive call
	insertSorted(stack,num);
}