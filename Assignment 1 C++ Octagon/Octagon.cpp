#include <iostream>
//By George Pope
using namespace std;

void mainMenu(); //This creates the prototype for the mainMenu function

class Octagon
{
private:
	int width; //Private values for use on Octagon class
	int type;	

public:
	//sets
	void setWidth(int newWidth)
	{
		width = newWidth;
	}
	void setType(int newType)
	{
		type = newType;
	}
	//gets
	int getWidth()
	{
		return width;
	}
	int getType()
	{
		return type;
	}

	void display()
	{
		int spaces; //This keeps track of the spacing on top and bottom of the octagon
		char* fillCharacter;//This keeps track of the fillCharacter that's printed
		int topCount;//This keeps track of the counting of lines to print on the top part of the octagon
		int bottomCount;//This keeps track of the counting of lines to print on the bottom part of the octagon
		bool evenLineCounter = false;//Returns false if the line number is odd or true is it's even
		int horLineCounter = 1;//This counts the number of characters used for the middle section
		int evenNumCounter = 1;//This counts the number of lines used for the project
		int evenWidth = width;//Keeps track of the original width until after middle section
		int originalWidth = width;//Always keeps track of the original width

		spaces = width + 1;//Counts spaces to the width + 1
		topCount = width;//Counter for top section when drawing lines
		bottomCount = width;//Counter for top section when drawing lines


		if (type == 1) //If user has selected type 1(blank), then use fill character 'space'
		{
			fillCharacter = " ";
		}

		if (type == 2) //If user has selected type 2 (fill), then use fill character '+'
		{
			fillCharacter = "+";
		}

		if (type == 3) //If user has selected type 3(horizontal lines), then use fill character '-'
		{
			fillCharacter = "-";
		}

		if (type == 4)  //If user has selected type 4 (vertical lines), then use fill character '|'
		{
			fillCharacter = "|";		
		}

		if (type == 5)  //If user has selected type 5 (crossed lines) , then use fill character '+'
		{
			fillCharacter = "+";
		}


		for(int x = 0; x < spaces; x++)//Draws the spacing for the very top line 
		{
			cout << " ";
		}

		for(int y = 0; y < width; y++)//Draws the '_'s for the very top line 
		{
			cout << "_";
		}
		cout << endl;

		evenLineCounter = false;	

		/////////////////START OF TOP OF OCTAGON DRAW/////////////////
		for(int t = 0; t < topCount; t++)//Prints the right amount of lines
		{
			for(int s = 1; s < spaces; s++)//Draws the spacing for the lines
			{
				cout << " ";
			}
			cout << "/";//Finishes the line with a '/'	
			horLineCounter = horLineCounter + 1;
			for(int x = 0; x < width; x++)//Prints the right amount of characters
			{		
				if(type==3)
				{
					if(horLineCounter%2==0)//If character number is even then print '-' else ' '
					{
						fillCharacter = "-";							
					}
					else
					{ 
						fillCharacter = " ";							
					}
				}
				if(type==4)
				{
					if(originalWidth % 2 == 0)//If original width is even then...
					{
						if(evenLineCounter)//If bool is true then print ' '
						{		
							fillCharacter = " ";
							evenLineCounter = false;
							if(horLineCounter%2!=0)// If the character is odd then print a '|'
							{
								fillCharacter = "|";
							}

						}
						else //If bool is false then...
						{
							fillCharacter = " "; //If original width is odd then print ' '
							evenLineCounter = true;	
							if(horLineCounter%2==0)//If the character is even then print a '|'
							{
								fillCharacter = "|";
							}
						}
					}
					else //If original width is odd then...
					{
						if(evenLineCounter)//If bool is true then print '|'
						{		
							fillCharacter = "|";
							evenLineCounter = false;

						}
						else//If bool is true then print ' '
						{
							fillCharacter = " ";
							evenLineCounter = true;						
						}
					}
				}
				if(type==5&&originalWidth%2==0)//If using type 5, and width is even..
				{
					if(evenLineCounter)//If bool is true then print '+'
					{
						fillCharacter = "+";
						evenLineCounter = false;						
						if(evenWidth %2==0)//However if evenWidth is even then print '| '
						{
							fillCharacter = "| ";								
						}
					}
					else//If bool is false then print '+'
					{
						fillCharacter = "-";
						evenLineCounter = true;	
						if(evenWidth %2==0)//However if evenWidth is even then print ''
						{
							fillCharacter = "";
						}
					}
				}
				if(type==5&&originalWidth%2!=0)//If using type 5, and width is odd..
				{
					if(evenLineCounter)//If bool is true then print '|'
					{
						fillCharacter = "|";
						evenLineCounter = false;						
						if(evenWidth %2==0)//However if evenWidth is even then print '+- '
						{
							fillCharacter = "+-";								
						}
					}
					else//If bool is false then print ' '
					{
						fillCharacter = " ";
						evenLineCounter = true;	
						if(evenWidth %2==0)//However if evenWidth is even then print ''
						{
							fillCharacter = "";
						}
					}
				}
				cout << fillCharacter;
			}		
			if(type==4)//This corrects the last character on each line as the wrong one is printed.
			{
				if(evenWidth%2!=0 && originalWidth%2==0)//If the evenWidth is not even and original width is even then...
				{
					cout<<'\b';//Removes the last character and prints..
					cout<<"|";
				}
				if(evenWidth%2==0 && originalWidth%2!=0)//If the evenWidth is even and original width is not even then...
				{
					cout<<'\b';//Removes the last character and prints..
					cout<<"|";
				}
			}
			if(type==5)//This corrects the last character on each line as the wrong one is printed.
			{
				if(evenWidth%2!=0 && originalWidth%2==0)//If the evenWidth is not even and original width is even then...
				{
					cout<<'\b';//Removes the last character and prints..
					cout<<"+";
				}
				if(evenWidth%2==0 && originalWidth%2!=0)//If the evenWidth is even and original width is not even then...
				{
					cout<<'\b';//Removes the last character
				}
			}
			cout << "\\ " << endl;			
			width = width + 2; //This makes the fill 2 more, creating the octagons lines
			evenWidth = evenWidth+1;
			spaces = spaces - 1; //This removes a space count each time to work with the fill			
		}
		evenLineCounter = true;	

		/////////////////START OF MIDDLE OF OCTAGON DRAW/////////////////
		for(int t = 0; t < topCount; t++)//Prints the right amount of lines
		{
			cout << "|";
			evenLineCounter = true;
			horLineCounter = horLineCounter + 1;//Counts each line, starts at 1..
			for (int z = 0; z < width; z++)//Prints the right amount of characters
			{	
				if(type==3)
				{
					if(horLineCounter%2==0)//If the line number is even then print '-'
					{
						fillCharacter = "-";							
					}
					else //If the line number is odd then print ' '
					{ 
						fillCharacter = " ";							
					}
				}
				if(type==4)
				{
					if(evenLineCounter)//If the bool is true then print '|'
					{
						fillCharacter = "|";

						evenLineCounter = false;
					}
					else//If the bool is false then print ' '
					{
						fillCharacter = " ";
						evenLineCounter = true;
					}
				}
				if(type==5)
				{
					if(horLineCounter %2==0)//If the line number is even then...
					{
						if(evenLineCounter)//If the bool is true then print '|'
						{		
							fillCharacter = "|";
							evenLineCounter = false;

						}
						else//If the bool is false then print ' '
						{
							fillCharacter = " ";
							evenLineCounter = true;						
						}
					}
					else//If the line number is odd then...
					{
						if(evenLineCounter)//If the bool is true then print '+'
						{		
							fillCharacter = "+";
							evenLineCounter = false;

						}
						else//If the bool is true then print '-'
						{
							fillCharacter = "-";
							evenLineCounter = true;						
						}
					}
				}
				cout << fillCharacter;
				evenWidth = evenWidth+1;
			}
			cout << "|" << endl;
		}
		width = width - 2;
		spaces = 1;			
		evenLineCounter = true;

		/////////////////START OF BOTTOM OF OCTAGON DRAW/////////////////
		for(int t = 0; t < bottomCount; t++)//Prints the right amount of lines
		{
			if(originalWidth % 2 == 0)//If the original width is even..
			{
				if(type == 4)
				{
					if(evenLineCounter)//Switch the bool to correct for an even input
					{
						evenLineCounter = false;
					}
					else//Switch the bool to correct for an even input
					{
						evenLineCounter = true;
					}
				}
			}
			for(int s = 0; s < spaces; s++)//Draws the spacing for the lines
			{
				cout << " ";
			}
			cout << "\\";
			horLineCounter = horLineCounter + 1;
			for(int x = 0; x < width; x++)//Prints the right amount of characters
			{		
				if(type==3)
				{
					if(horLineCounter%2==0)//If the line number is even then print '-'
					{
						fillCharacter = "-";							
					}
					else//If the line number is odd then print ' '
					{ 
						fillCharacter = " ";							
					}
				}
				if(type==4)
				{
					if(originalWidth % 2 == 0)//If the original width is even..
					{
						if(evenLineCounter)//if the bool is true..
						{		
							fillCharacter = "|";
							evenLineCounter = false;

						}
						else//if the bool is false..
						{
							fillCharacter = " ";
							evenLineCounter = true;						
						}
					}
					else//If the original width is eodd..
					{
						if(evenLineCounter)//if the bool is true..
						{		
							fillCharacter = " ";
							evenLineCounter = false;

						}
						else//if the bool is false..
						{
							fillCharacter = "|";
							evenLineCounter = true;						
						}
					}
				}
				if(type==5)
				{
					if(horLineCounter% 2 == 0)//If the line number is even then..
					{
						if(evenLineCounter)//If the bool is true...
						{		
							fillCharacter = " ";
							evenLineCounter = false;

						}
						else//If the bool is false...
						{
							fillCharacter = "|";
							evenLineCounter = true;						
						}
					}
					else//If the line number is odd then..
					{
						if(evenLineCounter)//If the bool is true...
						{
							evenLineCounter = false;
							if(originalWidth % 2 == 0)//If the original width was even..
							{
								fillCharacter = "+";
							}
							else//If the original width was odd..
							{
								fillCharacter = "-";

							}
						}
						else//If the bool is false...
						{
							evenLineCounter = true;	
							if(originalWidth % 2 == 0)//If the original width was even..
							{
								fillCharacter = "-";
							}
							else
							{
								fillCharacter = "+";
							}
						}
					}
				}

				if(t == bottomCount-1)//Prints the final '_'s for the bottom line
				{
					fillCharacter = "_";
				}
				cout << fillCharacter;				
			}	
			if(fillCharacter != "_")//If the final '_' has been printed then change to a '/'
			{
				cout << "/" << endl;
			}				
			width = width - 2;   //This makes the fill 2 less, creating the octagons lines
			evenWidth = evenWidth+1;
			spaces = spaces + 1; //This adds a space count each time to work with the fill
		}
		cout << "/" << endl;
	}
};

int main()
{
	system("cls");
	while(true)
	{
		int inputFromMenu;
		do {//If the input is not 1 or 0 then loop
			cout<<"Enter 1 for new octagon design and 0 to exit: ";
			cin>>inputFromMenu;
		}while(inputFromMenu>1||inputFromMenu<0);//If the input is not 1 or 0 then loop
		if(inputFromMenu == 1) //Send state to mainMenu if input is 1
		{
			mainMenu(); //Changes state to mainMenu
		}  
		if(inputFromMenu == 0) //Otherwise exit the program.
		{
			exit(2);
		}
	}
}

void mainMenu()
{	
	int octagonSize;
	int fillType;

	Octagon oct1;

	system("cls");	//Clears the console window
	cout<<"Enter the size of the octagon at its widest point: ";
	cin>>octagonSize;
	oct1.setWidth(octagonSize);//Send the input the Octagon class
	cout<<endl;

	cout<<"Enter the type of fill of your octagon..."<<endl;
	cout<<"     1) Clear"<<endl;
	cout<<"     2) Filled"<<endl;
	cout<<"     3) Horizontal lines"<<endl;  
	cout<<"     4) Vertical lines"<<endl;   
	cout<<"     5) Crossed lines"<<endl;
	cout<<"Type: ";
	cin>>fillType;

	if(fillType<1||fillType>5)//If the input is not between 1 and 5 then loop
	{
		mainMenu();
	}

	oct1.setType(fillType);//Send the input the Octagon class

	cout<<endl;
	cout<<endl;

	oct1.display();//Go to the Octagons display function.

	cout<<endl;
	cout<<endl;

	int anotherExit;	
	do{//If the input is not between 1 or 2 then loop
		cout << "Draw a new octagon? Yes = 1, No (exit) = 2 : ";	
		cin >> anotherExit;	
		if (anotherExit == 2)//Exit if input is 2
		{
			exit(2);
		}	
	}while(anotherExit<1||anotherExit>2);//If the input is not between 1 or 2 then loop
	main();	//go to MAIN if input is 1
}