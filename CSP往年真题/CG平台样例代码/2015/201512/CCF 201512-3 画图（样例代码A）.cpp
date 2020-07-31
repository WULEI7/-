#include "iostream"
#include "algorithm"
#include "stack"

using namespace std;

int W, H, N;
char canvas[101][101];

struct Pos {
  int x, y;
  Pos(int x_, int y_): x(x_), y(y_) {}
};

void drawLine(int x0, int y0, int x1, int y1) 
{
  if(y0==y1) // draw horizontal line
  {
    if(x0>x1) swap(x0, x1);
    for(int x=x0; x<=x1; x++)
      if(canvas[y0][x] == '|') canvas[y0][x] = '+';
      else if(canvas[y0][x] != '+') canvas[y0][x] = '-';
  }
  else // draw vertical line
  {
    if(y0>y1) swap(y0, y1);
    for(int y=y0; y<=y1; y++)
      if(canvas[y][x0] == '-') canvas[y][x0] = '+';
      else if(canvas[y][x0] != '+') canvas[y][x0] = '|';
  }
}

bool legal(int x, int y)
{
  return x>=0 && x<W && y>=0 && y<H;
}

void fill(int x, int y, char c) 
{
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  stack<Pos> s;
  s.push(Pos(x, y));
  canvas[y][x] = c;
  while(!s.empty())
  {
    Pos p = s.top();
    s.pop();
    for(int i=0; i<4; i++)
    {
      Pos np(p.x+dx[i], p.y+dy[i]);
      if(legal(np.x, np.y) && canvas[np.y][np.x]!='+' && canvas[np.y][np.x]!='|' 
         && canvas[np.y][np.x]!='-' && canvas[np.y][np.x]!=c)
      {
        canvas[np.y][np.x] = c;
        s.push(np);
      }
    }
  }
}

int main() 
{
  cin >> W >> H >> N;
  for(int y=0; y<H; y++)
    for(int x=0; x<W; x++)
      canvas[y][x] = '.';
  for(int n=0; n<N; n++) 
  {
    int type;
    cin >> type;
    int x0, y0, x1, y1;
    char c;
    if(type==0) 
    {
      cin >> x0 >> y0 >> x1 >> y1;
      drawLine(x0, y0, x1, y1);
    }
    else 
    {
      cin >> x0 >> y0 >> c;
      fill(x0, y0, c);
    }
  }
  for(int h=H-1; h>=0; h--)
  {
    for(int w=0; w<W; w++)
      cout << canvas[h][w];
    cout << endl;
  }
}

