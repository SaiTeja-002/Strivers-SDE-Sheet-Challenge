void fill(int oldColor, int newColor, int x, int y, int n, int m, vector<vector<int>> &image)
{
    if(x<0 || x>=n || y<0 || y>=m || image[x][y] != oldColor)
        return ;

    image[x][y] = newColor;

    fill(oldColor, newColor, x+1, y, n, m, image);
    fill(oldColor, newColor, x-1, y, n, m, image);
    fill(oldColor, newColor, x, y+1, n, m, image);
    fill(oldColor, newColor, x, y-1, n, m, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(image[x][y] == newColor)
        return image;

    int oldColor = image[x][y];

    fill(oldColor, newColor, x, y, image.size(), image[0].size(), image);

    return image;
}