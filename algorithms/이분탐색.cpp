/*
    알고리즘: 이분 탐색
    복잡도: log2(N) * 비교비용
    설명
        1.  오름차순으로 정렬된 배열 하나에서 값을 찾는다고하자,

        2.  원소가 하나뿐이라면, 그것이 찾는 값일것이니 반환한다.
            아니라면, 정렬된 상태이므로 그 배열의 중앙의 원소가 값보다 작다면, 중앙을 기준으로 왼쪽에 존재하지 않다. 따라서 오른쪽만 다시 탐색한다.(1)로 돌아가면 된다.
*/

/*
    이분 탐색 구현 예시

    인자
        컨테이너
        값
        비교함수 = less
    반환값
        [시작, 끝)사이의 값중 비교함수(원소,값)가 처음으로 거짓인 It 반환
    복잡도
        log2(last - 시작) * 비교함수
*/
template <class Container, class T, class Compare>
auto bsearch(Container c,const T& value,Compare cmp=std::less<T>())
{
    auto begin = std::begin(c);
    auto end = std::end(c);
    auto dis = end - begin;
    while(dis){
        auto it=begin + dis/2;
        if(cmp(*it,value)){
            first = it + 1;
            dis -= dis/2 + 1;
        }else
            dis/=2;
    }
    return first;
}

/*
    upper_bound

    <algorithm>에 정의됨
    인자
        It 시작
        It 끝
        const T& 값
        Compare 비교함수
    반환값
        [시작, 끝)사이의 값중 !비교함수(값,원소)가 처음으로 참인 It 반환
    복잡도
        log2(last - 시작) * 비교함수
*/
template<class It, class T,class Compare>
It upper_bound(It 시작,It 끝,const T& 값,Compare 비교함수=std::less<>());

/*
    lower_bound

    <algorithm>에 정의됨
    인자
        It 시작
        It 끝
        const T& 값
        Compare 비교함수
    반환값
        [시작, 끝)사이의 값중 비교함수(원소,값)가 처음으로 거짓인 It 반환
    복잡도
        log2(last - 시작) * 비교함수
*/
template<class It,class T,class Compare=void*>
constexpr It lower_bound(It 시작,It 끝,const T& 값,Compare 비교함수=std::less<>());