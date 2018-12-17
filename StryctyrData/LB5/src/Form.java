import javax.swing.*;
import java.awt.*;


public class Form extends JFrame {
    public static void main(String[] args) {
        new Form();
    }

    private JPanel rootpanel;
    private JButton Udel;
    private JButton Add;
    private JButton Ddel;
    private JButton Ldel;
    private JButton Del;
    private JButton Ladd;
    private JScrollPane ScrollPanel;
    private JPanel PaintPanel;
    private JTextField Data;
    private ThreadedTree MassData = new ThreadedTree();
    Form() {
        setContentPane(rootpanel);
        pack();
        Add.addActionListener(e -> {MassData.insert(Integer.parseInt(Data.getText()));; repaint();});
        Del.addActionListener(e -> {MassData.delete(Integer.parseInt(Data.getText())); repaint();});
        ScrollPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        ScrollPanel.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(700,500);
        setVisible(true);
    }

    private void createUIComponents() {
        PaintPanel = new JPanelMy();
    }

    class JPanelMy extends JPanel {
        int RootSize = 0;
        int xSize = 320; int xSizeL = 320*3;
        int ySize = 30; int ySizeL = 50;
        int TextSize = 15;

        @Override
        public void paint(Graphics g) {
            super.paint(g);
            int x,y=0;
            ThreadedTree.Node My = MassData.root;
            g.setColor(Color.black);
            RootSize = 0;
            x = SerchSize(My,0);
            setSize(new Dimension(x*xSize*4+30,RootSize*100+30));
            setPreferredSize(new Dimension(x*xSize*4+30,RootSize*100+30));
            paintNode(g,30,30,My);
        }

        private void paintNode(Graphics g, int x, int y, ThreadedTree.Node ThisPaint){
            g.drawRect(x,y,xSize,ySize);
            g.drawRect(x+xSize,y,xSize,ySize);
            g.drawRect(x+xSize+xSize,y,xSize,ySize);
            g.drawString(ThisPaint.left.toString() +" "+ThisPaint.leftThread,x,y+TextSize);
            g.drawString(ThisPaint.toString() +" "+ThisPaint.key,x+xSize,y+TextSize);
            g.drawString(ThisPaint.right.toString() +" "+ThisPaint.rightThread,x+xSize+xSize,y+TextSize);
            if(!ThisPaint.leftThread) paintNode(g,x,y+ySizeL+10,ThisPaint.left);
            if(!ThisPaint.rightThread) paintNode(g,x+xSize+xSize+xSize+10,y+ySizeL+10,ThisPaint.right);
        }

        int SerchSize(ThreadedTree.Node SizeLoop, int ThisLoop){
            ThisLoop++;
            int LSize = ThisLoop, RSize = ThisLoop;
            if(!SizeLoop.leftThread) {
                LSize = SerchSize(SizeLoop.left, ThisLoop);
            } else RootSize++;
            if(!SizeLoop.rightThread) {
                RSize = SerchSize(SizeLoop.right, ThisLoop);
            } else RootSize++;
            return LSize>RSize ?  LSize : RSize;
    }
}
}