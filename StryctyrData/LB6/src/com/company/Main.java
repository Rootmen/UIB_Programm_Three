package com.company;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {new Main();}

    Main() {
        Scanner TextInfo = new Scanner(System.in);
        Hashtable<String,SetData> MassStr = new Hashtable<>();
        int n = 0;
        while (n != 4){
            n = menu();
            switch (n){
                case 1:{
                    System.out.print("Введите id для структуры - любой текстовое поле: ");
                    String TextId = TextInfo.nextLine();
                    MassStr.put(TextId,new SetData(TextId));
                    break;
                }
                case 2:{
                    System.out.print("Введите id для структуры - любой текстовое поле: ");
                    String TextId = TextInfo.nextLine();
                    SetData Data = MassStr.get(TextId);
                    System.out.println(Data.PrintData());
                    System.out.println("Что необходимо сделать? Добавить новую запись или удалить существующу?");
                    TextId = TextInfo.nextLine();
                    if(TextId.equals("Добавить")){
                        System.out.print("Введите id второй структуры: ");
                        TextId = TextInfo.nextLine();
                        SetData Data2 = MassStr.get(TextId);
                        if(Data.addLinkinMe(Data2)) {
                            System.out.println("УСПЕХ!");
                            System.out.println(Data.PrintData());
                            System.out.println(Data2.PrintData());
                        } else {
                            System.out.println("НЕУДАЧА! Проверьте наличие свободных связей!");
                        }
                        break;
                    }

                    if(TextId.equals("Удалить")){
                        System.out.print("Введите id второй структуры: ");
                        TextId = TextInfo.nextLine();
                        SetData Data2 = MassStr.get(TextId);
                        Data.delete(Data2);
                        } else {
                            System.out.println("НЕУДАЧА! Проверьте наличие свободных связей!");
                        }
                        break;
                    }
                case 3:{
                    Enumeration en = MassStr.keys();
                    while(en.hasMoreElements())
                        System.out.println(MassStr.get(en.nextElement()).PrintData());
                    }
                    
                }


            }


        }


    static int menu(){
        Scanner TextInfo = new Scanner(System.in);
        System.out.println("Меню работы программы");
        System.out.println("1)Добавить элемент");
        System.out.println("2)Изменить связь для элемента");
        System.out.println("3)Вывод информации");
        System.out.println("4)Выход");
        System.out.print("Ваш выбор:");
        return TextInfo.nextInt();
    }




    class SetData {
        SetData L_in_me[];
        SetData L_to_me[];
        String id;

        SetData(String id_L) {
            L_to_me = new SetData[5];
            L_in_me = new SetData[2];
            id = id_L;
        }


        boolean addLinktoMe(SetData Linked) {
            for (int g = 0; g < 5; g++) { if (L_to_me[g] == null){ L_to_me[g] = Linked; return true;} }
            return false;
        }

        boolean addLinkinMe(SetData Linked) {
            for (int g = 0; g < 2; g++) {
                if (L_in_me[g] == null){
                    if(!Linked.addLinktoMe(this)) return false;
                    L_in_me[g] = Linked;
                    return true;
                }
            }
            return false;
        }

        boolean delete(SetData Linked) {
            for (int g = 0; g < 2; g++) {
                if (L_in_me[g] == Linked){
                    L_in_me[g] = null;
                    Linked.delete2(this);
                }
            }
            return false;
        }
        
        boolean delete2(SetData Linked) {
            for (int g = 0; g < 2; g++) {
                if (L_to_me[g] == Linked){
                    L_to_me[g] = null;
                }
            }
            return false;
        }
        
        public String PrintData() {
            String PrintData = "id структуры - " + id + "\nСвязи в структуре\nОна ссылаеться на \n";
            for (int g = 0; g < 2; g++) {
                String DataOfelem = L_in_me[g] ==null ?  "null" : L_in_me[g].toString();
                PrintData += "Ссылка на элемент: " + DataOfelem;
            if(L_in_me[g] != null){
                PrintData += " Его id " + L_in_me[g].id;
            }
                PrintData += "\n";
            }
            PrintData += "На него ссылаеться\n";
            for (int g = 0; g < 5; g++) {
                String DataOfelem = L_to_me[g] ==null ?  "null" : L_to_me[g].toString();
                PrintData += "Ссылка на элемент: " + DataOfelem;
                if(L_to_me[g] != null){
                    PrintData += " Его id " + L_to_me[g].id;
                }
                PrintData += "\n";
            }
            return PrintData;
        }
    }

}
