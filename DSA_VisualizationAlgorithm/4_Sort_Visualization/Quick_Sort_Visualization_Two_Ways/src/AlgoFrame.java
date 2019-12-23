import javax.swing.*;
import java.awt.*;

public class AlgoFrame extends JFrame {

    private int canvasWidth;
    private int canvasHeight;

    public AlgoFrame(String title, int canvasWidth, int canvasHeight){
        super(title);  // 窗口标题

        this.canvasWidth = canvasWidth;
        this.canvasHeight = canvasHeight;

        AlgoCanvas canvas = new AlgoCanvas();
//        canvas.setPreferredSize(new Dimension(canvasWidth, canvasHeight));  // 设置画布大小
        setContentPane(canvas);  // 将canvas设置成内容面板

        setResizable(false);  // 窗口大小不能改变大小
        pack();  // 调用该方法后才能在窗口中显示面板

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // 使得鼠标点击窗口叉号之后能正常退出
        setVisible(true);  // 使窗口可见
    }

    public AlgoFrame(String title){
        this(title, 1024, 768);
    }

    public int getCanvasWidth() { return canvasWidth; }
    public int getCanvasHeight() { return canvasHeight; }

    private QuickSortData data;
    public void render(QuickSortData data){
        this.data = data;
        repaint();  // 将画布中的所有控件刷新一遍：将AlgoCanvas清空，重新调用AlgoCanvas中的paintComponent方法
    }

    private class AlgoCanvas extends JPanel{  // 有关画布的类
        public AlgoCanvas(){  // JPanel默认支持双缓存
            // 双缓存
            super(true);  // JPanel默认支持双缓存
        }

        @Override
        public void paintComponent(Graphics g){  // 我们不需要知道该参数g是如何得到的，g称为上下文环境
            super.paintComponent(g);

            Graphics2D g2d = (Graphics2D)g;  // 历史遗留问题

            // 抗锯齿
            RenderingHints hints = new RenderingHints(
                                        RenderingHints.KEY_ANTIALIASING,
                                        RenderingHints.VALUE_ANTIALIAS_ON);

            hints.put(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
            g2d.addRenderingHints(hints);  // 添加我们设置的抗锯齿功能

            // 具体绘制
            int w = canvasWidth / data.N();
            for (int i = 0; i < data.N(); i++){
                if (i >= data.l && i <= data.r)
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Green);
                else
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Grey);

                if (i == data.curPivot)
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Yellow);
                if (i >= data.l + 1 && i <= data.curL)
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
                if (i >= data.curR && i <= data.r)
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.LightBlue);
                if (data.fixedPivots[i])
                    AlgoVisHelper.setColor(g2d, AlgoVisHelper.Red);

                AlgoVisHelper.fillRectangle(g2d, i*w, canvasHeight - data.get(i), w-1, data.get(i));
            }

        }

        @Override
        public Dimension getPreferredSize(){  // 创建AlgoCanvas会自动调用该方法，从而决定画布的大小
            return new Dimension(canvasWidth, canvasHeight);  // 设置画布宽,高
        }
    }

}
