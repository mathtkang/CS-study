public class Main {
    public static void main(String[] args) {
        for (int m = 0; m < 10; m++) {
            if (m % 2 == 0)
                continue;
            System.out.print(m);
        }
    }
}
// continue;가 있으니까! m=0,2,4,6,8 일때는 System.out.print(m);를 타지 않음
// System.out.print(m); 는 ln이 없는 개행이 없기 때문에
// >>> 13579 (띄어쓰기, 개행 없이 출력)