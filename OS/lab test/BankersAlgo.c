#include<studio.h>
#define MaxP 10
#define MaxR 10
int n,m;
int Allocation[MaxP][MaxR];
int Max[MaxP][MaxR];
int Need[MaxP][MaxR];
int Available[MaxR];
void calculateNeed(){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Need[i][j]=Max[i][j] - Allocation[i][j];
        }
        }
    }
int safetyAlgorithm(){
    int Work[MaxR];
    int Finish[maxP]={0};
    int SafeSequence[MaxP];
    int count=0;

    for (int i=0;i<m;i++){
        Work[i]=Available[i];

    }
    while(count<n){
        int found=0;
        for (int i=0;i<n;i++){
            if (Finish[i]==0){
                int possible=1;
                for (int j=0;j<m;j++){ //check
                    if (Need[j]>Work[j]){//not possible
                        possible=0;
                        break;
                    }
                }//
                if (possible){ //can execute
                    for( int j=0;j<m;j++){
                        Work[j]+=Allocation[i][j];
                    }
                    SafeSequence[count++]=i;
                    Finish[i]=1;
                    found=1;
                }
            }
        }
        if (!found)
            {
                printf(\n"System is in Unsafe Mode");
                return 0;
            }
        }
            printf("\n System is in Safe state");
            printf("safe seqence : ");
            for (int i=0;i<n;i++){
                printf("P%d", SafeSequence[i])
                if (i!=n-1) printf(" -> ");
                }
            printf("\n");
             
            return 1;
     }
        
    void resourceRequest(){
        
    }