#include <stdio.h>

typedef struct id{
	int preLeft, preRight, postRight, postLeft, inLeft, inRight, rootNow, subLeft, subRight;
}id;


int preorder[8002], postorder[8002], inorder[8002];

int isSameTree(id idx);

int main(){
	int n, i;
	id indeks;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++) scanf("%d", &preorder[i]);
	
	for(i=0;i<n;i++) scanf("%d", &postorder[i]);
	
	for(i=0;i<n;i++) scanf("%d", &inorder[i]);
	
	indeks.inLeft=0;
	indeks.inRight=n-1;
	indeks.postLeft=0;
	indeks.postRight=n-1;
	indeks.preLeft=0;
	indeks.preRight=n-1;
	
	
	if(isSameTree(indeks)) printf("yes\n");
	else printf("no\n");
	
	return 0;
}

int isSameTree(id idx){
	int i, hasilKanan, hasilKiri;
	id temp;
	if(preorder[idx.preLeft] != postorder[idx.postRight]) return 0;
	if(idx.preLeft == idx.preRight) return 1;
	
	for(i=idx.inLeft;i<=idx.inRight;i++){
		if(preorder[idx.preLeft] == inorder[i]){
			idx.rootNow=i;
			break;
		}
	}
	idx.subLeft= idx.rootNow - idx.inLeft;
	idx.subRight = idx.inRight - idx.rootNow;
	
	temp=idx;
	
	idx.preLeft = idx.preLeft+1;
	idx.preRight = idx.inLeft+idx.subLeft;
	idx.postRight = idx.postLeft+idx.subLeft-1;
	idx.inRight = idx.inLeft+idx.subLeft-1;
	
	hasilKiri = isSameTree(idx);
	
	temp.preLeft = temp.preRight-temp.subRight+1;
	temp.postLeft = temp.postRight-temp.subRight;
	temp.postRight = temp.postRight-1;
	temp.inLeft = temp.inRight-temp.subRight+1;
	
	
	hasilKanan = isSameTree(temp);
	
	if(hasilKanan && hasilKiri) return 1;
}
