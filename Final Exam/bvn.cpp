int search(int M[], int k, int n){
    int pos= -1;
    for(int i=0; i<n; i++){
        if(!(i%2)&&M[i]==4*k*k&&!(n%2)){
            pos= i; break;
        }
        else if (i%2 && M[i]==k*k/16 && n%2){
            pos= k; break;
        }
    }
    return pos;
}

int search(int M[], int k, int n){
    int pos= -1;
    int odd= k*k<<2;
    int even= k*k>>4;
    int div= n%2;
    if(div){
        for(int i=0; i<n; i+=2){
            if (M[i+1]==even){
                pos= i+1; break;
            }
        }
    }
    else{
        for(int i=0; i<n; i+=2){
            if( M[i]==odd){
                pos= i; break;
            }
        }
    }
    return pos;
}

for (int i = 0; i<20000; i++ )
    for (int j = 0; j< 5; j++)
        sum += sin(i / 16 + 2 * j);

for(int j= 0; j<5; j++)
    for(int i=0; i< 20000>>4; i++)
        sum+= sin(i+ j<<1)

void findK(float b, float *a, int n){
    int I = 0, found = 0;
    while ((!found) && (i < n)){
    float x = log(b)/log(2);
    if (fabs(a[i] - x) < 1e-9) found = 1;
    else i++;
    }
    If (found) do_something;
}

void findK(float b, float *a, int n){
    int i = 0;
    float x = log(b)/log(2);
    a[n]= x;
    while ((fabs(a[i] - x) > 1e-9)){  
        i++;
    }
    if (i< n) do_something;
}
