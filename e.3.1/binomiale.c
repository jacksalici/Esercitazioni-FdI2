int BinomialeRec(int n, int k) {
	
	if (k == 0 || k == n)
		return 1;
	if (k > n || k < 0)
		return 0;
	
	return BinomialeRec(n - 1, k - 1) + BinomialeRec(n - 1, k);

}

int Binomiale(int n, int k) {
	if (n < 0)
		return -1;
	else
		return BinomialeRec(n, k);
}