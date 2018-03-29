/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


 */

/**
 * 关键都在于记录斜率，但是有可能使用浮点数会出现特例，因此使用两个int，但是需要使用求最大公约数的函数
 */

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 2) return points.size();
        int max_res = 2;
        for(size_t i = 0; i < points.size() - 1; ++i) {
            unordered_map<double, int> xielv;
            auto& p = points[i];
            int cnt = 0;
            for(size_t j = i + 1; j < points.size(); ++j) {
                auto& q = points[j];
                if(q.x == p.x && q.y == p.y) {
                    ++cnt;
                    continue;
                }
                double fenmu = static_cast<double>(q.y - p.y);
                int fenzi = q.x - p.x;
                double xie = fenzi == 0 ? 3.402823466e+38F : fenmu / static_cast<double>(fenzi);
                if(xielv.find(xie) != xielv.end()) ++xielv[xie];
                else xielv.emplace(xie, 2);
            }
            for(auto& pa : xielv) {
                max_res = std::max(max_res, cnt + pa.second);
            }
            if(xielv.empty()) max_res = std::max(max_res, 1 + cnt);
        }
        return max_res;
    }
};


class Solution {
public:
    int maxPoints(vector<Point> &points) {
        
        if(points.size()<2) return points.size();
        
        int result=0;
        
        for(int i=0; i<points.size(); i++) {
            
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;
            
            for(int j=i+1; j<points.size(); j++) {
                
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    
                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {
                    
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);
                    
                    a/=gcd;
                    b/=gcd;
                    
                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }

                localmax=max(vertical, localmax);
            }
            
            result=max(result, localmax+overlap+1);
        }
        
        return result;
    }

private:
    int GCD(int a, int b) {
        
        if(b==0) return a;
        else return GCD(b, a%b);
    }
};