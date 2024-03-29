/*
    순위 검색
    https://programmers.co.kr/learn/courses/30/lessons/72412
*/
/*
let info_to_score = {
    // 개발언어: 2
    'cpp'       : 0b00 << 0,
    'java'      : 0b01 << 0,
    'python'    : 0b10 << 0,
    // 직군: 1
    'backend'   : 0b0 << 2,
    'frontend'  : 0b1 << 2,
    // 경력: 1
    'junior'    : 0b0 << 3,
    'senior'    : 0b1 << 3,
    // 소울푸드: 1
    'chicken'   : 0b0 << 4,
    'pizza'     : 0b1 << 4,
}

function can_info_to_number(can_info)
{
    return can_info.split(' ').forEach(v=>info_to_score[v]).reduce((a,b)=>a+b)
}
*/

let attribute_list = [
    ['chicken','pizza'],
    ['junior','senior'],
    ['backend','frontend'],
    ['cpp','java','python'],
]

function set_default(obj,idx,val)
{
    return obj[idx] = obj[idx] || val
}

// lower_bound
function lower_bound_helper(list, begin, end, is_pivot)
{
    let mid = (begin + end) >> 1
    if(begin == end)return begin
    
    if(is_pivot(list[mid]))
        return lower_bound_helper(list, begin, mid, is_pivot)
    else
        return lower_bound_helper(list, mid+1, end, is_pivot)
}

function lower_bound(list, is_pivot)
{
    return lower_bound_helper(list,0,list.length,is_pivot)
}

function find_greater_or_eq(list, pivot)
{
    pivot = +pivot
    if(list.sorted)return lower_bound(list.sorted, v=>v>=pivot)
    list.sorted = list.map(v=>+v).sort((a,b)=>a-b)
    return find_greater_or_eq(list,pivot)
}

function count_greater_or_eq(list, pivot)
{
    if(!list)return 0
    return list.length - find_greater_or_eq(list,pivot)
}

function solution(info, queries) {
    let answer = [];
    let scores = {}
    
    for(let i of info){
        i = i.split(' ')
        let score = i.pop()
        set_default(scores,i.join(' '),[]).push(score)
    }
    
    for(let query of queries){
        query = query.split(' ').filter(v=>v != 'and')
        let score = query.pop()
        let count = 0
        let now = []
        function count_all(query){
            if(!query.length){
                count+=count_greater_or_eq(scores[now.join(' ')],score)
                return;
            }
            let condition = query[0]
            if(condition == '-'){
                let list = attribute_list[query.length-1]
                for(let attribute of list){
                    now.push(attribute)
                    count_all(query.slice(1))
                    now.pop()
                }
            }else{
                now.push(condition)
                count_all(query.slice(1))
                now.pop()
            }
        }
        count_all(query)
        answer.push(count)
    }
    
    return answer;
}