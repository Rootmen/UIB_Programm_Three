import javax.swing.*;
import java.awt.*;




public class Form extends JFrame {
    public static void main(String[] args) {
        new Form();
    }

    private JPanel rootpanel;
    private JButton Udel;
    private JButton Uadd;
    private JButton Ddel;
    private JButton Ldel;
    private JButton Radd;
    private JButton Dadd;
    private JButton Ladd;
    private JButton Rdel;
    private JScrollPane ScrollPanel;
    private JPanel PaintPanel;

    Form() {
        setContentPane(rootpanel);
        pack();
        ScrollPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        ScrollPanel.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(700,550);
        setVisible(true);
    }

    private void createUIComponents() {
        PaintPanel = new JPanelMy();
    }

    class JPanelMy extends JPanel {

        public void paint(Graphics g) {
            super.paint(g);
            g.setColor(Color.black);
            setSize(new Dimension(800,700));
            setPreferredSize(new Dimension(800,700));
            g.fillOval(50, 50, 700, 800);
        }
    }
}


class MassData{
    class Dec{
        Next Dec


    }
    Dec Mass



        }