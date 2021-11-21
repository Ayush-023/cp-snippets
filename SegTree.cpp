class SegTree
{
	public:
	SegTree *lchild, *rchild;
	int leftmost, rightmost;
	int sum;

	SegTree(int leftmost, int rightmost, vector<int>& v)
	{
		this->leftmost = leftmost;
		this->rightmost = rightmost;
		if(leftmost==rightmost)//at leaf
		{
			sum = v[leftmost];
			return;
		} 
		int mid = (leftmost+rightmost)/2;
		lchild = new SegTree(leftmost, mid, v);
		rchild = new SegTree(mid+1, rightmost, v);
		recalc();
	}
	void recalc() //recalculates sum for the segment
	{
		if(leftmost==rightmost) return ;
		sum = lchild->sum + rchild->sum;
	}
	void pointUpdate(int index, int val)
	{
		if(leftmost==rightmost){
			sum+=val;
			return;
		}
		int mid = (leftmost+rightmost)/2;
		if(index<=mid) lchild->pointUpdate(index, val);
		else rchild->pointUpdate(index, val);
		recalc();
	}
	
	int rangeSum(int left, int right)
	{
 
		if(right<leftmost or left>rightmost) return 0;
		if(right>=rightmost and left<=leftmost) return sum;
		return lchild->rangeSum(left, right)+rchild->rangeSum(left, right);
 
	}
};