import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;


public class Form extends JFrame {
    public static void main(String[] args) {
        new Form();
    }

    private JPanel rootpanel;
    private JButton Udel;
    private JButton Uadd;
    private JButton Ddel;
    private JButton Ldel;
    private JButton Dadd;
    private JButton Ladd;
    private JScrollPane ScrollPanel;
    private JPanel PaintPanel;
    private MassDec MassData = new MassDec();
    Form() {
        setContentPane(rootpanel);
        pack();
        Ladd.addActionListener(e -> MassData.addL(null));
        Dadd.addActionListener(e -> MassData.addD());
        Uadd.addActionListener(e -> MassData = MassData.addU());
        Ddel.addActionListener(e -> MassData.delD());
        Ldel.addActionListener(e -> MassData.delL());
        Udel.addActionListener(e -> MassData = MassData.delU());
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

        public void paint(Graphics g) {
            super.paint(g);
            int xSize = 350; int xSizeL = 380;
            int ySize = 50; int ySizeL = 80;
            int TextSize = 5;
            int x=0,y=0;
            MassDec My = MassData;
            g.setColor(Color.black);
            setSize(new Dimension(x+60,y+60));
            setPreferredSize(new Dimension(x+60,y+60));
            for(x=30;; x=x+xSizeL) {
                MassDec My2 = My;
                for (y = 30;; y = y + ySizeL) {
                    String TextPrint = "";
                    g.drawRect(x, y, xSize, ySize);
                    if (My.U == null) TextPrint = "Адресс элемента с верху: 0";
                    else TextPrint = "Адресс элемента с верху: " + My.U.toString();
                    g.drawString(TextPrint, x + TextSize, y + ySize / 2 + TextSize);
                    y += ySize;
                    g.drawRect(x, y, xSize, ySize);
                    TextPrint = "Адресс этого элемента: " + My.toString();
                    g.drawString(TextPrint, x + TextSize, y + ySize / 2 + TextSize);
                    y += ySize;
                    g.drawRect(x, y, xSize, ySize);
                    if (My.L == null) TextPrint = "Адресс элемента с права: 0";
                    else TextPrint = "Адресс элемента с права: " + My.L.toString();
                    g.drawString(TextPrint, x + TextSize, y + ySize / 2 + TextSize);
                    y += ySize;
                    g.drawRect(x, y, xSize, ySize);
                    if (My.D == null) TextPrint = "Адресс элемента с низу: 0";
                    else TextPrint = "Адресс элемента с низу: " + My.D.toString();
                    g.drawString(TextPrint, x + TextSize, y + ySize / 2 + TextSize);
                    if(My.D == null) break;
                    My = My.D;
                }
                if(My2.L == null) break;
                My = My2.L;
            }
            setSize(new Dimension(x+60+xSizeL+60+60,y+60+ySizeL+60+60));
            setPreferredSize(new Dimension(x+60+xSizeL+60+60,y+60+ySizeL+60+60));

        }
    }
}


class MassDec{
    public MassDec U = null;
    public MassDec D = null;
    public MassDec L = null;

    MassDec addD(){
        if(D == null) D = new MassDec();
        else return D.addD();
        D.U = this;
        MassDec thisM = this;
        while (thisM.L != null){
            thisM.L.D = new MassDec();
            thisM.L.D.U = thisM.L;
            thisM.D.L = thisM.L.D;
            thisM = thisM.L;
        }
        return D;
    }

    MassDec addU(){
        U = new MassDec();
        U.D = this;
        MassDec ThisL = L;
        MassDec ThisU = U;
        while (ThisL != null){
            ThisU.L = new MassDec();
            ThisU.L.D = ThisL;
            ThisL.U = ThisU.L;
            ThisL = ThisL.L;
            ThisU = ThisU.L;
        }
        return U;
    }

    void addL(MassDec This){
        if(L != null) {L.addL(This);return;}
        if(This == null) This = new MassDec();
        L = This;
        if(D == null) return;
        MassDec ThisNew = new MassDec();
        ThisNew.U = This;
        This.D = ThisNew;
        D.addL(ThisNew);
    }

    boolean delL(){
        boolean log;
        if(L == null) {return true;}
        else log = L.delL();
        if(!log) return  false;
        MassDec thisM = this;
        L = null;
        while (thisM.D != null){
            thisM.D.L = null;
            thisM = thisM.D;
        }
        return false;
    }

    MassDec delD(){
        if(L != null) L.delD();
        MassDec thisM = this;
        while (thisM.D != null){thisM = thisM.D;}
        thisM.U.D = null;
        return thisM.U;
    }

    MassDec delU(){
        if(L != null) L.delU();
        D.delU_U();
        return D;
    }

    void delU_U(){
        U = null;
    }
}