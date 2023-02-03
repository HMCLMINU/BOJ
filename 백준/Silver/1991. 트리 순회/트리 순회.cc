#include <iostream>
#include <vector>

using namespace std;

int N;
char rt, l, r;

struct Node
{
    char left;
    char right;
};

vector<Node> v(26);

void preOrder(char node){ // 전위 순회
	// root - left - right
	if(node == '.') return;
	
	cout << node;
	preOrder(v[node].left);
	preOrder(v[node].right);
}

void inOrder(char node){ // 중위 순회
	// left - root - right
	if(node == '.') return;
	
	inOrder(v[node].left);
	cout << node;
	inOrder(v[node].right);
}

void postOrder(char node){ // 후위 순회
	// left - right - root
	if(node == '.') return;
	
	postOrder(v[node].left);
	postOrder(v[node].right);
	cout << node;
}

int main(){	
    // freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	
	char rt, l, r;
	for(int i = 0; i < n; i++){
		cin >> rt >> l >> r;		
		v[rt].left = l;
		v[rt].right = r;
	}
	
	preOrder('A');
	cout << "\n";
	
	inOrder('A');
	cout << "\n";
	
	postOrder('A');
	
	return 0;
}