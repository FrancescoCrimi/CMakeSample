using System.Runtime.InteropServices;

namespace TestBindings
{
    public unsafe partial struct MyClass
    {
        [NativeTypeName("std::string")]
        private basic_string<sbyte, char_traits<sbyte>, allocator<sbyte>> name;

        [DllImport("", CallingConvention = CallingConvention.ThisCall, EntryPoint = "??0MyClass@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", ExactSpelling = true)]
        public static extern MyClass(MyClass* pThis, [NativeTypeName("const std::string &")] basic_string<sbyte, char_traits<sbyte>, allocator<sbyte>>* name);

        [DllImport("", CallingConvention = CallingConvention.ThisCall, EntryPoint = "?getName@MyClass@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ", ExactSpelling = true)]
        [return: NativeTypeName("std::string")]
        public static extern basic_string<sbyte, char_traits<sbyte>, allocator<sbyte>> getName(MyClass* pThis);

        [DllImport("", CallingConvention = CallingConvention.ThisCall, EntryPoint = "?display@MyClass@@QEBAXXZ", ExactSpelling = true)]
        public static extern void display(MyClass* pThis);
    }
}
