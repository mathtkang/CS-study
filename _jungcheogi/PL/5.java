public class Main {
    public static void main(String[] args) {
        int k = 10;
        int a = 3;

        switch (k++) {
            case 10:
                a += 2;
            case 11:
                a *= k;
            case 8:
                break;
            case 9:
                a %= 2;
        }
        System.out.println(a);
        System.out.println(k);
    }
}
// k++ : k의 값을 먼저 case에 넣고 이후 1증가해줌
// case10 을 탄다. break가 없기 때문에 case 11도 탄다. -> 끝
// >>> 55 / 11