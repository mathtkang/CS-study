public class Main {
    public static void main(String[] args) {
        String s = "red"; // 변수 s에 red 문자열 저장
        boolean[] b = new boolean[1]; // 불린 자료형을 갖는 배열 b를 선언 및 배열의 크기를 2로 초기화
        // 값을 초기화하지 않았기 때문에, b[0]=b[1]=false 이다.
        if (b[0]) // false기 때문에 if문을 타지 않음
            s = "blue";
        System.out.println(s);
        // 따라서 s값 그대로 출력! >>> "red"
    }
}
