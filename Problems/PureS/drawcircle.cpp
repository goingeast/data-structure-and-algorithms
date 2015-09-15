vector< pair<int, int> > drawCircle( int radius, int x0, int y0){
	vector< pair<int, int> > result;
	int x = radius;
	int y = 0;
	while(x*x <= radius*radius){
		for(int y =  0; y < x+1; ++y){
			if(x*x + y*y == radius*radius)
				result.insert(x0+x, y0+y);
				result.insert(x0+x, y0-y);
				result.insert(x0-x, y0+y);
				result.insert(x0-x, y0-y);

				result.insert(x0+y, y0+x);
				result.insert(x0+y, y0-x);
				result.insert(x0-y, y0+x);
				result.insert(x0-y, y0-x);

		}
	}
}

void circleMidpoint(int xCenter, int yCenter, int radius)
    {
        int x = 0;
        int y = radius;
        int p = (5 - radius*4)/4;

        circlePoints(xCenter, yCenter, x, y, pix);
        while (x < y) {
            x++;
            if (p < 0) {
                p += 2*x+1;
            } else {
                y--;
                p += 2*(x-y)+1;
            }
            
            circlePoints(xCenter, yCenter, x, y, pix);
        }
    }
def draw_circle_bi_search(r2):
    result = Set([])
    x = 1
    y = 0
    while x*x <= r2:
        y_start = 0
        y_end = x
        while y_start <= y_end:
            y_mid = y_start+(y_end-y_start)/2
            if x*x + y_mid*y_mid == r2:
                result.update(Set([(x,y_mid),(x,-y_mid),(-x,-y_mid),(-x,y_mid),(y_mid,x),(y_mid,-x),(-y_mid,-x),(-y_mid,x)]))
                break
            elif x*x + y_mid*y_mid < r2:
                y_start = y_mid+1
            else:
                y_end = y_mid-1
                
                 
        x+=1
    return result
