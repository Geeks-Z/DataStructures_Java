package cn.edu.nuaa.stack;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * @ClassName InfixExpression2SuffixExpression
 * @Description 代码参考《韩顺平数据结构与算法-Java版》
 * @Author Geeks_Z
 * @Date 2021/3/1 16:25
 * @Version 1.0
 **/
public class InfixExpression2SuffixExpression {

    /**
     *完成将一个中缀表达式转成后缀表达式的功能
     *说明
     *1. 1+((2+3)×4)-5 => 转成  1 2 3 + 4 × + 5 –
     *2. 因为直接对str 进行操作，不方便，因此 先将  "1+((2+3)×4)-5" =》 中缀的表达式对应的List
       即 "1+((2+3)×4)-5" => java.util.ArrayList [1,+,(,(,2,+,3,),*,4,),-,5]
     *3. 将得到的中缀表达式对应的List => 后缀表达式对应的List
       即 ArrayList [1,+,(,(,2,+,3,),*,4,),-,5]  =》 ArrayList [1,2,3,+,4,*,+,5,–]
     */

    public static void main(String[] args) {
        String str = "1+((2+3)*4)-5";
        String expression = "1+((2+3)*4)-5";//注意表达式
        List<String> infixExpressionList = InfixExpression2List(expression);
        System.out.println("中缀表达式对应的List=" + infixExpressionList); // ArrayList [1,+,(,(,2,+,3,),*,4,),-,5]
        List<String> suffixExpreesionList = parseSuffixExpreesionList(infixExpressionList);
        System.out.println("后缀表达式对应的List" + suffixExpreesionList); //ArrayList [1,2,3,+,4,*,+,5,–]
    }

    public static List<String> parseSuffixExpreesionList(List<String> ls){
        //定义两个栈
        // s1符号栈
        Stack<String> s1 = new Stack<String>();
        //s2 这个栈，在整个转换过程中，没有pop操作，且最后需要逆序输出，所以使用 List<String> s2
        List<String> s2 = new ArrayList<String>();
        for (String item : ls) {
            if(item.matches("\\d+")){
                s2.add(item);
            }else if(item.equals("(")){
                s1.push(item);
            }else if(item.equals(")")){
                while(!s1.peek().equals("(")){
                    s2.add(s1.pop());
                }
                //!!! 将 ( 弹出 s1栈， 消除小括号
                s1.pop();
            }else {
                while(s1.size() != 0 && Operation.getPriority(s1.peek()) >= Operation.getPriority(item)){
                    s2.add(s1.pop());
                }
                //跳出循环时item优先级高于s1栈顶元素优先级，将其加入到s1
                s1.push(item);
            }
        }

        //处理s1中剩余元素
        while (s1.size() != 0){
            s2.add(s1.pop());
        }
        return s2;
    }


    /**
     * 中缀表达式转为相应的list
     * @param s
     * @return
     */
    public static List<String> InfixExpression2List(String s){
        List<String> ls = new ArrayList<>();
        //定义一个指针用于遍历中缀表达式
        int index = 0;
        //定义一个字符串，用于拼接多位数
        String str;
        //定义一个字符，存放遍历的字符
        char c;
        do{
            //如果c是一个非数字，直接加入到ls中
            if((c = s.charAt(index)) < 48 || (c = s.charAt(index)) > 57){
                ls.add("" + c);
                index++;
            } else{ //考虑多位数的情况
              str = "";
              while( index < s.length() && (c = s.charAt(index)) >= 48 && (c = s.charAt(index)) <= 57){
                  str += c;
                  index++;
              }
              ls.add(str);
            }
        }while(index < s.length());
        return ls;
    }
}

//编写一个类 Operation 可以返回一个运算符 对应的优先级
class Operation {
    private static int ADD = 1;
    private static int SUB = 1;
    private static int MUL = 2;
    private static int DIV = 2;

    //写一个方法，返回对应的优先级数字
    public static int getPriority(String operation) {
        int result = 0;
        switch (operation) {
            case "+":
                result = ADD;
                break;
            case "-":
                result = SUB;
                break;
            case "*":
                result = MUL;
                break;
            case "/":
                result = DIV;
                break;
            default:
                System.out.println("不存在该运算符" + operation);
                break;
        }
        return result;
    }

}
