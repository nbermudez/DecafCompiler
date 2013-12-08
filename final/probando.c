class hola
{
	int hola1;
	int hola2;

	int funcionHola(int i1, int i2)
	{
		if(i1 == i2)
		{
			return i1;
		}
		return funcionHola(i1,i2-1);
	}

	void main(){
		int x;
		x = funcionHola(3,10);
		print x;
	}
}