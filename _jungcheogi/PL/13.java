public class Main {
    public static void main(String[] args) {
        int x = 5, y = 0, z = 0;
        y = x++; // x를 y에 대입 후 x를 증가
        z = --x; // x를 감소 후 x에 대입
        System.out.printf(x + ", " + y + ", " + z); // >>> 3,3,3
    }
}