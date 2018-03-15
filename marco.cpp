inline int binarySearch(int search, int data[]){
	int low = 0, high = marbleNum -1;
	int mid;

	while(low <= high){

		mid = (low + high)/2;

		if(data[mid] == search)
			return mid;
		else if(search > data[mid])
			low = mid + 1;
		else if(data[mid] > search)
			high = mid - 1;

	}

	return -1;
}

inline void quicksort( int start, int end, int array[] )
{
    if( start < end )
    {
        int piv = start;
        int i;
        int temp;
        for( i = start+1 ; i < end ; i++ )
            if( array[i] < array[start] )
            {
                piv++;

                temp = array[i];
                array[i] = array[piv];
                array[piv] = temp;
            }

        temp = array[start];
        array[start] = array[piv];
        array[piv] = temp;

        quicksort( start, piv, array );
        quicksort( piv+1, end, array );
    }
}

void mergesort(int data[], int low, int high){
int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(data,low,mid);
		mergesort(data,mid+1,high);
		merge(data,low,high,mid);
	}
}

void merge(int data[], int low, int high, int mid){
int i, j, k, c[50];
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid)&&(j<=high)){
		if(data[i]<data[j]){
			c[k]=data[i];
			k++;
			i++;
		}else{
			c[k]=data[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		c[k]=data[i];
		k++;
		i++;
	}
	while(j<=high){
		c[k]=data[j];
		k++;
		j++;
	}
		for(i=low;i<k;i++){
			data[i]=c[i];
		}
}

void heappush(int x){
	int i = top++;
	while( i > 0){
		int p = (i - 1)/2;
		if( heap[p] <= x )	break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
	return;
}

int heappop(){
	int out = heap[0];
	int x = heap[--top];
	int i = 0;
	while( i *2 + 1 < top){
		int a = i * 2 + 1, b = i * 2 + 2;
		if( b < top && heap[b] < heap[a])	a = b;
		if(heap[a] >= x)		break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return out;
}
