public class MineSweepData {

    public static final String blockImageURL = "resources/block.png";
    public static final String flagImageURL = "resources/flag.png";
    public static final String mineImageURL = "resources/mine.png";
    public static String numberImageURL(int num){
        if (num < 0 || num >= 8)
            throw new IllegalArgumentException("No such a number image");
        return "resources/" + num + ".png";
    }

    private int N, M;  // 雷的行数，列数
    private boolean[][] mines;  // mines[i][j] = true 代表 第i行第j列 有雷
    private int[][] numbers;  // numbers[i][j] = k 代表 第i行第j列 周围有k个雷
    public boolean[][] open;  // open[i][j] = true 代表 第i行第j列 被点开
    public boolean[][] flags;  // flags[i][j] = true 代表 第i行第j列 被插旗

    public MineSweepData(int N, int M, int mineNumber){
        if(N <= 0 || M <= 0)
            throw new IllegalArgumentException("Mine sweep size is invalid!");

        if(mineNumber < 0 || mineNumber > N*M)
            throw new IllegalArgumentException("Mine number is larger than the size of mine sweep board!");

        this.N = N;
        this.M = M;

        mines = new boolean[N][M];
        numbers = new int[N][M];
        open = new boolean[N][M];
        flags = new boolean[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++){
                mines[i][j] = false;
                numbers[i][j] = 0;
                open[i][j] = false;
                flags[i][j] = false;
            }

        generateMines(mineNumber);  // 生成mineNumber个雷
        calculateNumbers();  // 计算每个位置对应的雷的数量，有雷的地方numbers[i][j] = -1
    }

    public int N(){ return N; }
    public int M(){ return M; }

    public boolean isMine(int x, int y){
        if(!inArea(x, y))
            throw new IllegalArgumentException("Out of index in isMine function!");
        return mines[x][y];
    }

    public int getNumber(int x, int y){
        if(!inArea(x, y))
            throw new IllegalArgumentException("Out of index in getNumber function!");
        return numbers[x][y];
    }

    public boolean inArea(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    private void generateMines(int mineNumber){
        for (int i = 0; i < mineNumber; i++){
            int x = i / M;
            int y = i % M;
            mines[x][y] = true;
        }

        // Fisher-Yates-Knuth洗牌算法
        for (int i = N*M-1; i >= 0; i--){
            int iX = i / M;
            int iY = i % M;

            int randomNumber = (int)(Math.random() * (i+1));

            int randomX = randomNumber / M;
            int randomY = randomNumber % M;
            swap(iX, iY, randomX, randomY);
        }
    }

    private void swap(int x1, int y1, int x2, int y2){
        boolean t = mines[x1][y1];
        mines[x1][y1] = mines[x2][y2];
        mines[x2][y2] = t;
    }

    private void calculateNumbers(){
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++){
                if (mines[i][j]) {
                    numbers[i][j] = -1;
                    continue;  // 原代码中没有考虑到这一点
                }

                numbers[i][j] = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                    for (int jj = j - 1; jj <= j + 1; jj++)
                        if (inArea(ii, jj) && isMine(ii, jj))
                            numbers[i][j]++;
            }

        return;
    }

    // 用户点开一个不是雷的位置后，打开一片区域，floodfill算法
    public void open(int x, int y){
        if(!inArea(x, y))
            throw new IllegalArgumentException("Out of index in open function!");

        if(isMine(x, y))
            throw new IllegalArgumentException("Cannot open an mine block in open function.");

        open[x][y] = true;
        if (0 == getNumber(x, y)){
            for (int i = x - 1; i <= x + 1; i++)
                for (int j = y - 1; j <= y + 1; j++)
                    if (inArea(i, j)  // 没有越界
                            && !open[i][j]  // 还没打开
                            && !isMine(i, j))  // 不是雷
                        open(i, j);
        }
    }
}
