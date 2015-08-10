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
