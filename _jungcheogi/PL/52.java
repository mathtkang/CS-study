public class Main {
    public static void main(String[] args) {
        int n = 10;
        increase(n);
        System.out.println(n);
    }

    static void increase(int n) {
        n = n + 1;
        // return이 없기 때문에, 7번째 줄의 print에서는 변동 없이 n = 10 이 출력
    }
}
// 맞음! 잘했어!