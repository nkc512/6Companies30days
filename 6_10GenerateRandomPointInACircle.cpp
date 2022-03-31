class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        this->x_center=x_center;
        this->y_center=y_center;
    }
    
    vector<double> randPoint() {
        double random1=(double)rand()/RAND_MAX;//[0,1]
        double pi=3.14159265359;
        double theta= 2*pi*random1;
        
        double random2=(double)rand()/RAND_MAX;
        
        double len=sqrt(random2)*radius;//[0,1], probability density
        
        double x_r=x_center+len*cos(theta); //rcos(theta)
        double y_r=y_center+len*sin(theta); //rsin(theta)
        
        return {x_r,y_r};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */