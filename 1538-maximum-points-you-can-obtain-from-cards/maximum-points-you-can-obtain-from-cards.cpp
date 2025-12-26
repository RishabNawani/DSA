class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==k){
            int sum=0;
            for(int i=0;i<cardPoints.size();i++){
                sum+=cardPoints[i];
            }
            return sum;
        }
        int n=cardPoints.size();
        

        int total=0;
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int maxp=total;

        for(int i=0;i<k;i++){
            total-=cardPoints[k-1-i];
            total+=cardPoints[n-1-i];

            maxp=max(maxp,total);
        }
        return maxp;

        /*
        int left=0;
        int summ=0;

        for(int i=1;i<k;i++){
            summ+=cardPoints[i];
        }
        summ+=cardPoints[left];

        int right=n-1;
        int summm=0;
        for(int i=n-2;i>=n-k;i--){
            summm+=cardPoints[i];
        }

        summm+=cardPoints[right];

        if(summm>summ) return summm;
        return summ;

        
        int left=0;
        
        int maxx=0;
        int maxind=0;
        for(int i=1;i<n-1;i++){
            if(cardPoints[i]>maxx){
                maxx=cardPoints[i];
                maxind=i;
            }
        }
        int summ=maxx;
        cardPoints.erase(cardPoints.begin()+maxind);
        
        int maxi=0;
        for(int i=1;i<n-1;i++){
            maxi=max(maxi,cardPoints[i]);
        }

        summ+=maxi;
        if(k>2){
            if(cardPoints[0]>cardPoints[n-1]) summ+=cardPoints[0];
            else summ+=cardPoints[n-1];
        }

        return summ;
        */
    }
};