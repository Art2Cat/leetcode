fn main() {
    let mut a = vec![1, 2, 3, 0, 0, 0];
    let m = 3;
    let mut b = vec![2, 5, 6];
    let n = 3;
    merge(&mut a, m, &mut b, n);
    println!("{:?}", a);
}

pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {

    nums1.drain(m as usize..);
    nums2.drain(n as usize..);
    nums1.append(nums2);
    nums1.sort();
}
