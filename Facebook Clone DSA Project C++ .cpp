#include<iostream>
#include <ctime>
#include<string>
#include<stack>
#pragma warning(disable : 4996)
using namespace std;
class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	void set_Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void set_hour(int h)
	{
		hour = h;
	}
	void set_min(int m)
	{
		min = m;
	}
	void set_sec(int s)
	{
		sec = s;
	}
	int get_hour()
	{
		return hour;
	}
	int get_min()
	{
		return min;
	}
	int get_sec()
	{
		return sec;
	}
	void display()
	{
		cout << get_hour() << ":" << get_min() << ":" << get_sec() << endl;
	}


};
class Date
{
private:
	int month;
	int day;
	int year;


public:
	void setDate(int temp_day, int temp_month, int temp_year)
	{
		day = temp_day;
		month = temp_month;
		year = temp_year;
	}
	void set_day(int temp_day)
	{
		day = temp_day;
	}
	void  set_month(int temp_month)
	{
		month = temp_month;
	}

	void set_year(int temp_year)
	{
		year = temp_year;

	}

	int get_month()
	{
		return month;
	}
	int get_day()
	{
		return day;
	}
	int get_year()
	{
		return year;

	}
	void display()
	{
		cout << get_day() << "/" << get_month() << "/" << get_year() << endl;
	}


};
class pNode {
public:
	char ch;
	bool terminal;
	pNode *child[27];

	pNode(char c)
	{
		ch = c;
		terminal = false;
		for (int i = 0; i < 27; i++)
		{
			child[i] = NULL;
		}
	}
};
class Tries
{
public:
	pNode* root;

	Tries()
	{
		root = createNode('\0');
	}

	pNode* createNode(char c)
	{
		pNode *newNode = new pNode(c);
		return newNode;
	}

	void Insert(string word)
	{
		pNode* temp = root;
		char ch = '\0';
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];
			pos = ch - 'a';
			if (pos < 1 || pos>27)
			{
				temp->child[pos] = createNode(ch);
			}
			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch);
			}
			temp = temp->child[pos];
		}
		temp->terminal = true;
	}
	void Display(pNode* temp, string word)
	{
		if (temp == NULL)
			return;

		if (temp != root)
			word = word + temp->ch;
		if (temp->terminal)
			cout << word << endl;
		for (int i = 0; i < 27; i++)
		{
			Display(temp->child[i], word);
		}
	}

	pNode* search(pNode* temp, string key, int index)
	{

		if (temp == NULL)
		{
			return false;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return false;
		}
		int i = ch - 'a';

		return	search(temp->child[i], key, ++index);

	}
};
class Post
{
private:
	Post *Next;
	Post *previous;
	string uname;
	string post;
	int postno;
	Post *cmlist = NULL;
	Date D;
	Time T;
public:
	Post()
	{
		uname = " ";
		post = " ";
		postno = 0;
		Next = NULL;
		previous = NULL;
	}
	void setPostNo(int no)
	{
		postno = no;
	}
	void Set_Post(string N, Date d, Time tm, string P, int no)
	{
		uname = N;
		D = d;
		T = tm;
		post = P;
		postno = no;

	}
	void setComment(string N, Date d, Time t, string P)
	{
		uname = N;
		D = d;
		T = t;
		post = P;


	}
	void setUsername(string n)
	{
		uname = n;
	}
	string getUserName()
	{
		return uname;
	}
	int getPostNo()
	{
		return postno;
	}
	void setNext(Post *val)
	{
		Next = val;
	}
	Post* getNext()
	{
		return Next;
	}
	void setPrevious(Post *pre)
	{
		previous = pre;
	}
	Post* getPreviuos()
	{
		return previous;
	}
	void setPost(string p)
	{
		post = p;
	}
	string  getPost()
	{
		return post;
	}
	void displayPost()
	{
		cout << "\t\t\t\t\tPost#" << getPostNo() << endl;
		cout << "\t\t\t\t\t" << getUserName() << endl;
		cout << "\t\t\t\t\t";
		D.display();
		cout << "\t\t\t\t\t";
		T.display();
		cout << "\n\t\t\t\t\t" << getPost() << endl;
		cout << "\t\t\t\t\t------------------------" << endl;
	}
	void displayComment()
	{
		cout << "\t\t\t\t\t" << getUserName() << endl;
		cout << "\t\t\t\t\t";
		D.display();
		cout << "\n\t\t\t\t\t";
		T.display();
		cout << "\t\t\t\t\t" << getPost() << endl;
		cout << "\t\t\t\t\t------------------------" << endl;
	}
	void insertComment(Post p)
	{
		Post *mynode = new Post(p);
		if (cmlist == NULL)
		{
			cmlist = mynode;
			cmlist->setNext(NULL);
		}
		else
		{
			Post *temp = cmlist;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			temp->setNext(mynode);
			mynode->setNext(NULL);
		}
	}
	void DisplayCommentList()
	{
		Post *temp = cmlist;
		if (temp == NULL)
		{
			cout << "No recent Comment" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				temp->displayComment();
				temp = temp->getNext();
			}
		}
	}
};
class PostList
{
public:
	Post *Head;
	Post *Tail;
public:
	PostList(Post *H = NULL, Post *T = NULL)
	{
		Head = H;
		Tail = T;
	}
	void setHead(Post *h)
	{
		Head = h;
	}
	Post* getHead()
	{
		return Head;
	}
	void Push(Post  pst)
	{
		Post *mynode = new Post(pst);
		if (Tail == NULL && Tail == NULL)
		{
			Head = mynode;
			Tail = mynode;

			Tail = Head;
			Tail->setNext(Tail);
			Tail->setPrevious(Tail);
		}
		else
		{
			Tail->setNext(mynode);
			mynode->setPrevious(Tail);
			Tail = Tail->getNext();
			Tail->setNext(Head);
			Head->setPrevious(Tail);

		}

	}
	void display()
	{
		Post *temp = Tail;
		if (temp == NULL)
		{
			cout << "No recent Post" << endl;
		}
		else
		{
			while (temp->getPreviuos() != Tail)
			{
				temp->displayPost();
				temp = temp->getPreviuos();
				cout << "  ";
			}
			temp->displayPost();
		}

	}
	Post* comment(int psno)
	{
		Post *temp = Tail;
		while (temp->getPreviuos() != Tail)
		{
			if (temp->getPostNo() == psno)
			{
				return temp;
				//temp->displayPost();
				break;
			}
			temp = temp->getPreviuos();
		}
		if (temp->getPreviuos() == Tail && temp->getPostNo() == psno)
		{
			return temp;
			//temp->displayPost();
		}

	}
	void Remove(int psno)
	{
		int flag = 0;
		Post *temp = Head;
		if (temp->getPostNo() == psno && temp->getPreviuos() == Tail)
		{
			flag = flag + 1;
			if (temp->getNext() == temp)
			{
				Tail = NULL;
			}
			else
			{
				temp->getNext()->setPrevious(temp->getPreviuos());
				Head = temp->getNext();
				/*temp->Next = NULL;
				temp->previous = NULL;
				delete temp;*/
				Head->getPreviuos()->setNext(Head);
				//Head->setPrevious(Tail);
			}

		}
		else
		{
			while (temp->getNext() != Head)
			{
				if (temp->getPostNo() == psno && temp->getNext() != Head && temp->getPreviuos() != Tail)
				{
					flag = flag + 1;
					temp->getPreviuos()->setNext(temp->getNext());
					temp->getNext()->setPrevious(temp->getPreviuos());
					/*temp->Next = NULL;
					temp->previous = NULL;*/
					//delete temp;
					break;
				}
				else
				{
					temp = temp->getNext();
				}
			}

			if (temp->getNext() == Head && temp->getPostNo() == psno)
			{
				flag = flag + 1;
				temp->getPreviuos()->setNext(temp->getNext());
				Tail = temp->getPreviuos();
				/*temp->Next = NULL;
				temp->previous = NULL;
				delete temp;*/
				Head->setPrevious(Tail);
			}

		}
		if (flag == 0)
		{
			cout << "no such Post exist " << endl;
		}

	}
	void Display()
	{
		Post *temp = Head;
		while (temp != NULL)
		{
			temp->getUserName();
			temp = temp->getNext();
		}

	}
};
class Node
{
private:
	Node *Left;
	Node *Right;
	Node *Next;
	Node *previous;
	PostList  postList;
	PostList HpostList;
	Node* friends;
	Node *friend_req;
	string Name;
	string Email;
	string Password;
	long long Ph;
public:
	stack <string> message[26];
	Node(string name, string email, string password, long long ph)
	{
		Name = name;
		Email = email;
		Password = password;
		Ph = ph;

	}
	Node()
	{
		Left = NULL;
		Right = NULL;
	}
	void setNext(Node *val)
	{
		Next = val;
	}
	void setHead(Node *f)
	{
		friends = f;
	}
	Node *getHead()
	{
		return friends;
	}
	Node* getNext()
	{
		return Next;
	}
	void setPrevious(Node *pre)
	{
		previous = pre;
	}
	Node* getPreviuos()
	{
		return previous;
	}
	void SetUser(string name, string email, string password, long long ph)
	{
		Name = name;
		Email = email;
		Password = password;
		Ph = ph;
	}
	void setLeft(Node *left)
	{
		Left = left;
	}
	void setRight(Node *right)
	{
		Right = right;
	}
	void set_Name(string name)
	{
		Name = name;
	}
	void set_Email(string email)
	{
		Email = email;

	}
	void set_Password(string password)
	{
		Password = password;

	}
	void set_Phone_No(long long ph)
	{
		Ph = ph;
	}
	Node* getLeft()
	{
		return Left;
	}
	Node* getRight()
	{
		return Right;
	}
	string get_Name()
	{
		return Name;
	}
	string get_Email()
	{
		return Email;

	}
	string get_Password()
	{
		return Password;
	}
	long long get_Phone_No()
	{
		return Ph;
	}
	void display()
	{
		cout << "\t\t\t\t\tUser name : " << get_Name() << endl;
		cout << "\t\t\t\t\tEmail : " << get_Email() << endl;
		cout << "\t\t\t\t\tPassword : " << get_Password() << endl;
		cout << "\t\t\t\t\tMobile No : " << get_Phone_No() << endl;
	}
	void AddPost(Post P)
	{
		postList.Push(P);
	}
	void AddPostHome(Post P)
	{
		HpostList.Push(P);
	}
	void friendRequest(Node* f)
	{
		if (friend_req == NULL)
		{
			friend_req = f;
			friend_req->setNext(NULL);
		}
		else
		{
			Node *temp = friend_req;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			temp->setNext(f);
			f->setNext(NULL);
		}
	}
	void dequeue()
	{
		int val = 0;
		if (friend_req != NULL)
		{
			friend_req = friend_req->getNext();
		}
	}
	void DisplayFrinedrequest(Node *p)
	{
		Node *temp = friend_req;
		if (temp == NULL)
		{
			cout << "\t\t\t\t\tNo Friend Request!!!!! " << endl;
		}
		while (temp != NULL)
		{
			char r;
			cout << "\t\t\t\t\t" << temp->get_Name() << " sends you a  friend request " << endl;
			cout << "\t\t\t\t\tDo you want to accept the request ?" << endl;
			cout << "\t\t\t\t\t";
			cin >> r;
			if (r == 'y' || r == 'Y')
			{
				p->dequeue();
				cout << "\t\t\t\t\tYou and  " << temp->get_Name() << " are now friends each other " << endl;
				p->insertFriend(temp);
				temp->insertFriend(p);
			}
			temp = temp->getNext();
		}

	}
	void insertFriend(Node *p)
	{
		//Post *mynode = new Post(p);
		if (friends == NULL)
		{
			friends = p;
			friends->setNext(NULL);
		}
		else
		{
			Node *temp = friends;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			temp->setNext(p);
			p->setNext(NULL);
		}
	}
	void Homepage(Post P, Node *p)
	{
		//p->AddPostHome(P);
		Node *temp = p;
		temp->AddPostHome(P);
		temp = temp->getNext();
		temp = friends;
		while (temp != NULL)
		{

			//temp->display();
			temp->AddPostHome(P);
			temp = temp->getNext();

		}
	}
	void HomeComment(Node *pstp, Node *p, Post cm, int psno)
	{
		Post *poSt;
		Node *temp = p;
		temp->hComment(psno)->insertComment(cm);
		temp = temp->getNext();
		temp = friends;
		while (temp != NULL)
		{

			poSt = temp->hComment(psno);
			//poSt->DisplayCommentList();
			poSt->insertComment(cm);
			temp = temp->getNext();


		}
		Node *temp2 = pstp->friends;
		while (temp2 != NULL)
		{
			Node *temp3 = friends;
			if (pstp->get_Name() != p->get_Name())
			{
				while (temp3 != NULL)
				{
					if (temp2->get_Name() != p->get_Name())
					{
						if (temp2->get_Name() != temp3->get_Name())
						{
							poSt = temp2->hComment(psno);
							poSt->insertComment(cm);
						}

					}

					temp3 = temp3->getNext();
				}

			}

			temp2 = temp2->getNext();
		}
	}
	void VeiwPostHome()
	{
		HpostList.display();
	}
	void DisplayHome(Node *p)
	{
		p->VeiwPostHome();
	}
	void DisplayFrinedList()
	{
		Node *temp = friends;
		while (temp != NULL)
		{
			cout << "\t\t\t\t\t" << temp->get_Name() << endl;
			temp = temp->getNext();
		}
	}
	void VeiwPost()
	{
		postList.display();
	}
	void Delete_Post_Home(int psno)
	{
		Node *temp = friends;
		while (temp != NULL)
		{
			temp->homeDelete(psno);
			temp = temp->getNext();
		}
	}
	void deltePost(int psno)
	{
		postList.Remove(psno);
		HpostList.Remove(psno);
	}
	void homeDelete(int psno)
	{
		HpostList.Remove(psno);
	}
	Post*  Comment(int psno)
	{
		return postList.comment(psno);
	}
	Post*  hComment(int psno)
	{
		return HpostList.comment(psno);
	}
};
class Tree
{
private:
	Node *root;
public:
	Tree()
	{
		root = NULL;
	}
	void setroot(Node *Root)
	{
		root = Root;
	}
	Node* getroot()
	{
		return root;
	}
	Node *insertAvl(Node n)
	{
		Node *node = new Node(n);
		if (root == NULL)
		{
			root = node;
		}
		else
		{
			Node *temp = root;
			int flag = 0;
			while (flag != 1)
			{
				if (n.get_Name() > temp->get_Name())
				{
					if (temp->getRight() == NULL)
					{
						temp->setRight(node);
						flag = 1;
					}
					temp = temp->getRight();
				}
				else
				{
					if (temp->getLeft() == NULL)
					{
						temp->setLeft(node);
						flag = 1;
					}
					temp = temp->getLeft();
				}

			}
			int BF = 0;
			BF = BalanceFactor(root);

			if (BF == 0 || BF == 1 || BF == -1)
			{

			}
			else
			{

				if (BF > 1 && n.get_Name() < root->getLeft()->get_Name())
				{
					root = rightRotate(root);

				}
				// Right Right Case
				else if (BF < -1 && n.get_Name()> root->getRight()->get_Name())
				{
					root = LeftRotate(root);
				}
				//Left Right Case
				else if (BF > 1 && n.get_Name() > root->getLeft()->get_Name())
				{
					root->setLeft(LeftRotate(root->getLeft()));
					root = rightRotate(node);
				}

				// Right Left Case
				else if (BF < -1 && n.get_Name() < root->getRight()->get_Name())
				{
					root->setRight(rightRotate(root->getRight()));
					root = LeftRotate(root);
				}

			}


		}
		return root;
	}
	int  BalanceFactor(Node* root)
	{
		int lh = Height(root->getLeft());
		int rh = Height(root->getRight());
		int bf = lh - rh;
		return bf;

	}
	Node *search(Node *root, string key)
	{

		int flag = 0;
		Node* temp = root;
		while (temp != NULL)
		{
			if (temp->get_Name() == key)
			{
				flag = 1;
				break;
			}
			else if (key < temp->get_Name())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}

		return temp;
	}
	int  BF(Node *root, string s)
	{
		Node * t = search(root, s);
		int lh = Height(t->getLeft());
		int rh = Height(t->getRight());
		int bf = lh - rh;
		return bf;

	}
	Node *rightRotate(Node *node)
	{
		Node *Lchild = node->getLeft();
		Node *R1 = Lchild->getRight();

		node->setLeft(R1);
		Lchild->setRight(node);
		return Lchild;
	}
	Node *LeftRotate(Node *node)
	{
		Node *Rchild = node->getRight();
		Node *L1 = Rchild->getLeft();

		Rchild->setLeft(node);
		node->setRight(L1);
		return Rchild;
	}
	int Height(Node* temp)
	{
		if (temp == NULL)
		{
			return -1;
		}
		else
		{
			// compute the height of each subtree 
			int lh = Height(temp->getLeft());
			int rh = Height(temp->getRight());
			//return  the larger one
			if (lh > rh)
			{
				return(lh + 1);
			}
			else
			{
				return(rh + 1);
			}

		}
	}
	void Predisplay(Node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		temp->display();
		cout << endl;
		Predisplay(temp->getLeft());
		Predisplay(temp->getRight());

	}
	int ascii(string s)
	{
		char c;
		int ASCII;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			c = s[i];
			ASCII = ASCII + int(c);

		}
		return ASCII;
	}

};
class Hash
{
private:

	int size = 26;
	Tree hash[26];
	Node *p = NULL;
	int index;
public:
	Hash(int size = 26)
	{

	}
	int hashindex(string s)
	{

		char c;
		int ASCII = 0;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			c = s[i];
			ASCII = ASCII + int(c);

		}
		index = ASCII % size;
		return index;

	}
	void hashInsert(Node n)
	{
		//Node *list;
		int i = hashindex(n.get_Name());
		hash[i].insertAvl(n);

		cout << "\t\t\t\t\tSign up successfully!!!!!" << endl;

	}
	void displayHash(string name)
	{
		int j = hashindex(name);
		Node *temp = hash[j].search(hash[j].getroot(), name);
		temp->display();
	}
	Node* login(string name)
	{

		int j = hashindex(name);

		return p = hash[j].search(hash[j].getroot(), name);


	}
};
int main()
{
	string key;
	Tries t;
	Hash h;
	Node n;
	string user_name;
	string password;
	string email;
	long long phno;
	int choice;
	Node *p = NULL;
	int postNo = 0;
	int day, month, year;
	int hour, min, sec;
	Date date;
	Time w;
	int Flag = 0;
l:cout << "\n\n\t\t\t\t\t\t Facebook " << endl;

h:cout << "\t\t\t\t\t1. Sign up" << endl;
	cout << "\t\t\t\t\t2. Login " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t         Personal Tab      " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t3. Add Post " << endl;
	cout << "\t\t\t\t\t4. View Posts" << endl;
	cout << "\t\t\t\t\t9. Delete Post " << endl;
	cout << "\t\t\t\t\t12. Veiw Comments  " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t         Home Tab          " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t8. Display HomePage " << endl;
	cout << "\t\t\t\t\t10. Comment on Post " << endl;
	cout << "\t\t\t\t\t11. Veiw Comments  " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t         Friends Tab       " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t5. Add Friends " << endl;
	cout << "\t\t\t\t\t6. Display Friend Request" << endl;
	cout << "\t\t\t\t\t7. Display FriendList" << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t       Messaging Tab       " << endl;
	cout << "\t\t\t\t\t---------------------------" << endl;
	cout << "\t\t\t\t\t13. Messaging" << endl;
	cout << "\t\t\t\t\tEnter Choice->";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n\n\t\t\t\t\tSignUp " << endl;
		cout << "\t\t\t\t\tEnter User Name  : ";
		cin.ignore();
		getline(cin, user_name);
		cout << "\t\t\t\t\tEnter Password  : ";
		cin >> password;
		cout << "\t\t\t\t\tEnter Email ID  : ";
		cin >> email;
		cout << "\t\t\t\t\tEnter ph_no  : ";
		cin >> phno;
		n.SetUser(user_name, password, email, phno);
		h.hashInsert(n);
		t.Insert(user_name);
		break;
	}
	case 2:
	{
		system("cls");
		cout << "\n\n\n\t\t\t\t\tLogin" << endl;
		string s;
		cout << "\t\t\t\t\tEnter User Name : ";
		cin >> s;
		string pass;
		cout << "\t\t\t\t\tEnter Password : ";
		cin >> pass;
		p = h.login(s);
		cout << "\t\t\t\t\tLogin Successfully" << endl;
		Flag = Flag + 1;
		break;
	}
	case 3:
	{

		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
	k:cout << "\n\n\n\t\t\t\t\tCreate Post" << endl;
		Post post;
		cout << "\t\t\t\t\t" << p->get_Name() << endl;
		string Pst;
		cout << "\t\t\t\t\tEnter post" << endl;
		cout << "\t\t\t\t\t";
		cin.ignore();
		getline(cin, Pst);
		time_t now = time(0);
		tm *ltm = localtime(&now);
		day = 1900 + ltm->tm_year;
		month = 1 + ltm->tm_mon;
		year = ltm->tm_mday;
		hour = ltm->tm_hour;
		min = ltm->tm_min;
		sec = ltm->tm_sec;
		postNo = postNo + 1;
		post.setPostNo(postNo);
		date.setDate(day, month, year);
		w.set_Time(hour, min, sec);
		post.Set_Post(p->get_Name(), date, w, Pst, postNo);
		p->AddPost(post);
		//p->AddPostHome(post);
		p->Homepage(post, p);
		char c;

		cout << "\n\t\t\t\t\tWould you like to Add another Post ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			system("cls");
			goto k;
		}
		break;
	}
	case 4:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! " << endl;
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tPersonal Profile" << endl;
		p->VeiwPost();
		break;
	}
	case 5:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tAdd Friends" << endl;
		cout << "\t\t\t\t\tEnter the name of the Friend that you want to search " << endl;
		cout << "\t\t\t\t\t";
		cin >> key;
		cout << "\t\t\t\t\tSuggesstion are...." << endl;
		pNode* temp = t.search(t.root, key, 0);
		key.erase(key.size() - 1);
		if (temp)
		{
			t.Display(temp, key);
		}
		else
			cout << "\t\t\t\t\tNot Found";
		Node *f = NULL;
		string Friend;
		cout << "\t\t\t\t\tEnter the name of the person who you want to send friend request" << endl;
		cout << "\t\t\t\t\t";
		cin >> Friend;
		f = h.login(Friend);
		cout << "\t\t\t\t\tRequest send to " << f->get_Name() << " successfully" << endl;
		//p->friendRequest(f);
		f->friendRequest(p);

		break;
	}
	case 6:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tFriendRequests" << endl;
		p->DisplayFrinedrequest(p);
		break;
	}
	case 7:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tFriendList" << endl;
		p->DisplayFrinedList();
		break;
	}
	case 8:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tHome Page" << endl;
		p->DisplayHome(p);
		break;
	}
	case 9:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		int postno;
		cout << "\n\n\n\t\t\t\t\tWhich Post you want to delete : ";
		cin >> postno;
		p->deltePost(postno);
		p->Delete_Post_Home(postno);
		break;
	}
	case 10:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		cout << "\n\n\n\t\t\t\t\tComments" << endl;
		int postno;
		cout << "\n\n\n\t\t\t\t\t On  Which Post you wanna comment: ";
		cin >> postno;
		Post ps;
		string cm;
		cout << "\t\t\t\t\t Enter your comment " << endl;
		cout << "\t\t\t\t\t";
		cin.ignore();
		getline(cin, cm);
		time_t now = time(0);
		tm *ltm = localtime(&now);
		day = 1900 + ltm->tm_year;
		month = 1 + ltm->tm_mon;
		year = ltm->tm_mday;
		hour = ltm->tm_hour;
		min = ltm->tm_min;
		sec = ltm->tm_sec;
		date.setDate(day, month, year);
		w.set_Time(hour, min, sec);
		ps.setComment(p->get_Name(), date, w, cm);
		Node *pstP;
		pstP = h.login(p->hComment(postno)->getUserName());
		p->HomeComment(pstP, p, ps, postno);

		break;
	}
	case 11:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}

		system("cls");
		int postno2;
		cout << "\n\n\n\t\t\t\t\t Enter Post whose comment you want to see: ";
		cin >> postno2;
		cout << "\n\n\n\t\t\t\t\tComments" << endl;
		p->hComment(postno2)->DisplayCommentList();
		break;
	}
	case 12:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		system("cls");
		int postno1;
		cout << "\n\n\n\t\t\t\t\t Enter Post whose comment you want to see: ";
		cin >> postno1;
		cout << "\n\n\n\t\t\t\t\tComments" << endl;
		p->hComment(postno1)->DisplayCommentList();
		break;
	}
	case 13:
	{
		if (Flag == 0)
		{
			cout << "Not login!!!!!! ";
			goto h;
		}
		int index, index2;
		string pharand, message;
		cout << "Enter the friend you want to send sms\n";
		cin >> pharand;

		index = h.hashindex(pharand);
		int count = 0;
		for (std::stack<string> dump = p->message[index]; !dump.empty(); dump.pop())
		{

			std::cout << dump.top() << '\n';
			count++;
			if (count == 10)
				break;
		}
		cout << "\t\t\t\t\tEnter Message  : ";
		cin.ignore();
		getline(cin, message);
		message += "  ; ";
		message += p->get_Name();
		p->message[index].push(message);


		index2 = h.hashindex(p->get_Name());
		Node* q = h.login(pharand);
		q->message[index2].push(message);
		break;
	}
	}
	char ch;
	cout << "\n\t\t\t\t\tWould you like to run another operation ";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		system("cls");
		goto l;
	}
	else
	{

		system("pause");
		exit(0);
	}







}