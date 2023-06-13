// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.1 (win64) Build 3865809 Sun May  7 15:05:29 MDT 2023
// Date        : Tue Oct 10 14:00:28 2023
// Host        : tsharpe-5950x running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode funcsim
//               c:/Users/todds/GitHub/toddsharpe/Nighthawk/Boards/artyz7/hardware/arty_z7.gen/sources_1/bd/design_1/ip/design_1_axi_bram_ctrl_0_bram_0/design_1_axi_bram_ctrl_0_bram_0_sim_netlist.v
// Design      : design_1_axi_bram_ctrl_0_bram_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_1_axi_bram_ctrl_0_bram_0,blk_mem_gen_v8_4_6,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_6,Vivado 2023.1" *) 
(* NotValidForBitStream *)
module design_1_axi_bram_ctrl_0_bram_0
   (clka,
    rsta,
    ena,
    wea,
    addra,
    dina,
    douta,
    clkb,
    rstb,
    enb,
    web,
    addrb,
    dinb,
    doutb,
    rsta_busy,
    rstb_busy);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE BRAM_CTRL, READ_WRITE_MODE READ_WRITE, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA RST" *) input rsta;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA EN" *) input ena;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA WE" *) input [3:0]wea;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [31:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DIN" *) input [31:0]dina;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [31:0]douta;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTB, MEM_SIZE 8192, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE BRAM_CTRL, READ_WRITE_MODE READ_WRITE, READ_LATENCY 1" *) input clkb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB RST" *) input rstb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB EN" *) input enb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB WE" *) input [3:0]web;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB ADDR" *) input [31:0]addrb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB DIN" *) input [31:0]dinb;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTB DOUT" *) output [31:0]doutb;
  output rsta_busy;
  output rstb_busy;

  wire [31:0]addra;
  wire [31:0]addrb;
  wire clka;
  wire clkb;
  wire [31:0]dina;
  wire [31:0]dinb;
  wire [31:0]douta;
  wire [31:0]doutb;
  wire ena;
  wire enb;
  wire rsta;
  wire rsta_busy;
  wire rstb;
  wire rstb_busy;
  wire [3:0]wea;
  wire [3:0]web;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_sbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire [31:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;

  (* C_ADDRA_WIDTH = "32" *) 
  (* C_ADDRB_WIDTH = "32" *) 
  (* C_ALGORITHM = "1" *) 
  (* C_AXI_ID_WIDTH = "4" *) 
  (* C_AXI_SLAVE_TYPE = "0" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_BYTE_SIZE = "8" *) 
  (* C_COMMON_CLK = "0" *) 
  (* C_COUNT_18K_BRAM = "0" *) 
  (* C_COUNT_36K_BRAM = "2" *) 
  (* C_CTRL_ECC_ALGO = "NONE" *) 
  (* C_DEFAULT_DATA = "0" *) 
  (* C_DISABLE_WARN_BHV_COLL = "0" *) 
  (* C_DISABLE_WARN_BHV_RANGE = "0" *) 
  (* C_ELABORATION_DIR = "./" *) 
  (* C_ENABLE_32BIT_ADDRESS = "1" *) 
  (* C_EN_DEEPSLEEP_PIN = "0" *) 
  (* C_EN_ECC_PIPE = "0" *) 
  (* C_EN_RDADDRA_CHG = "0" *) 
  (* C_EN_RDADDRB_CHG = "0" *) 
  (* C_EN_SAFETY_CKT = "1" *) 
  (* C_EN_SHUTDOWN_PIN = "0" *) 
  (* C_EN_SLEEP_PIN = "0" *) 
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     10.7492 mW" *) 
  (* C_FAMILY = "zynq" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "1" *) 
  (* C_HAS_ENB = "1" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_REGCEA = "0" *) 
  (* C_HAS_REGCEB = "0" *) 
  (* C_HAS_RSTA = "1" *) 
  (* C_HAS_RSTB = "1" *) 
  (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) 
  (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
  (* C_INITA_VAL = "0" *) 
  (* C_INITB_VAL = "0" *) 
  (* C_INIT_FILE = "NONE" *) 
  (* C_INIT_FILE_NAME = "no_coe_file_loaded" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "0" *) 
  (* C_MEM_TYPE = "2" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "2048" *) 
  (* C_READ_DEPTH_B = "2048" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "32" *) 
  (* C_READ_WIDTH_B = "32" *) 
  (* C_RSTRAM_A = "0" *) 
  (* C_RSTRAM_B = "0" *) 
  (* C_RST_PRIORITY_A = "CE" *) 
  (* C_RST_PRIORITY_B = "CE" *) 
  (* C_SIM_COLLISION_CHECK = "ALL" *) 
  (* C_USE_BRAM_BLOCK = "1" *) 
  (* C_USE_BYTE_WEA = "1" *) 
  (* C_USE_BYTE_WEB = "1" *) 
  (* C_USE_DEFAULT_DATA = "0" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_SOFTECC = "0" *) 
  (* C_USE_URAM = "0" *) 
  (* C_WEA_WIDTH = "4" *) 
  (* C_WEB_WIDTH = "4" *) 
  (* C_WRITE_DEPTH_A = "2048" *) 
  (* C_WRITE_DEPTH_B = "2048" *) 
  (* C_WRITE_MODE_A = "WRITE_FIRST" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "32" *) 
  (* C_WRITE_WIDTH_B = "32" *) 
  (* C_XDEVICEFAMILY = "zynq" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  (* is_du_within_envelope = "true" *) 
  design_1_axi_bram_ctrl_0_bram_0_blk_mem_gen_v8_4_6 U0
       (.addra({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,addra[12:2],1'b0,1'b0}),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,addrb[12:2],1'b0,1'b0}),
        .clka(clka),
        .clkb(clkb),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina(dina),
        .dinb(dinb),
        .douta(douta),
        .doutb(doutb),
        .eccpipece(1'b0),
        .ena(ena),
        .enb(enb),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .rdaddrecc(NLW_U0_rdaddrecc_UNCONNECTED[31:0]),
        .regcea(1'b0),
        .regceb(1'b0),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .rstb(rstb),
        .rstb_busy(rstb_busy),
        .s_aclk(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[3:0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_dbiterr(NLW_U0_s_axi_dbiterr_UNCONNECTED),
        .s_axi_injectdbiterr(1'b0),
        .s_axi_injectsbiterr(1'b0),
        .s_axi_rdaddrecc(NLW_U0_s_axi_rdaddrecc_UNCONNECTED[31:0]),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[31:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(wea),
        .web(web));
endmodule
`pragma protect begin_protected
`pragma protect version = 1
`pragma protect encrypt_agent = "XILINX"
`pragma protect encrypt_agent_info = "Xilinx Encryption Tool 2023.1"
`pragma protect key_keyowner="Synopsys", key_keyname="SNPS-VCS-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
aMT3usC6uizzcwnzOCX4OsS16Ob+YxFcsGovFpFklbnaIaD1S0lVdxenTwHPp6ByIEi+ehwr6Rgg
z/3AlTheI5NFTM8ihiMA18/wmUxI7EbaftJACA1LykUKCuj5myy0T+DACuv3sGYIZS38TZTZnnBC
FGAlvTZmRWs+JzneH3o=

`pragma protect key_keyowner="Aldec", key_keyname="ALDEC15_001", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
lR9ZerhYSAb39nzEkeYvhnwEs5t9y/+yTDf8KuoUtR1BGeHZq8pA/YxtjzQLtaOW1R1IQUb0FtSI
e3CYAb7WHYbIjcpw3vKHvW1SqcGn9CMGa556CYKmD2oF12Kow8xRaFvMSBUVxX7HsHxNWnRd+PU1
+C0YayU2KFIY/7Yl6cZ5luAzhw/6SW3PFYUIyyqWy5MCIXweHOwQR2IpQEdlDur5nluN7i7BeB+i
fxwwHh8TU/g7T4mhZFkiTuBKdLAtQOjxWxzqTMxgcuAjlTylY16FgMFOASdvvSbqBZJjbxMdVloU
rYjS8O/8rWktv8GXcaIdBJ2BRj01q7jsChsbwA==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VELOCE-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=128)
`pragma protect key_block
Qvl63GHz9mq2xOB7elt/vAQ7URLGdD1Lkcz7f3Wtw31dwjjjbP62Ny/Jr6OmBIheWlgejx38qxAT
TrHiiEyjKmGcnPn1Tn2n+cH4RAxCbOFnCI9n6+YsYMTe9JkplGhGGr39SkFgJz0I2IKpPsuqTjCj
rhf49TAryNMQeRpREJA=

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-VERIF-SIM-RSA-2", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
MA+9Ro+dh339m0iZrkKbqTKN8gQ5xkxN/SPCfhkOn+5jjgCTS5IOKLHil+HsZDjX333ebxnornwG
MOBxyEdFfLM8SA+bs2r41J/j0af2VVMmCM3hOh8JmZxB4X9Jg/glegNCbvwzqxMbOQNEy+zt7j5t
TFVD82RtPFmYVVYZZyll/WvAA+0aVpyjzLCIM1GznFky0RWLv65Wp4MJJnNRRrtG3muMznVO/u2s
tACsJ9jzv9M0IlMYjYH9BixhG6cZX02I4LEXXaPkhdOINlMMhsbArXtc9NphzmS4bY1/1yF1D6YD
EKLyS2Sr3HDl0O/lefN+jvfG8iKuVl55PNNrVQ==

`pragma protect key_keyowner="Real Intent", key_keyname="RI-RSA-KEY-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
wpMTg7STjFkUDhOqdNPa0FHXTnHQgKmhvqDv+rRVBvMiQ8O7u8oj7ibITq3o+jugJsMJ60B410gQ
JFTcqCJKYmYJvqi8rPLLOYDmFG6ZLP/Ixr3n62IyIaCeDltBahi3yV009QN0X+iuzuFCL+Y7g9ff
IvAgyBly+Z3Itv2H9EJMZPMl17Sa7IkgjmWqzVXIKNMKn0iDVYsQw6ZgzQDYQ8N8IvTIEggU3/lh
6Nf0hV0ev3qOv/2P+4w0U766Ux3yLuzPJSI7bKm3/ip9NjhOytxOiKKqVXhKG8dzbbuS5u3EE/eq
q6YxkL7gpvNltVqqBnJB6vHSyWrD6+MqsCtR9A==

`pragma protect key_keyowner="Xilinx", key_keyname="xilinxt_2022_10", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
Q7Q4SSp70lxFryaopuic9VVP/Ire0pSsPEIMYdURBAczC7ShkuYeV02U7L3BlAiyBE4vBKcwYSQd
cWiaj8sVP7q4kxoRHKxLV1R5PIO6l4DsLWE2E+1MLyUPME0w5KTular/oX8EPCJ5n/8VCtW7x4Vf
dpeyki1/IAPJkAyi3zVZKHzgKhEwnZaZZtZYuMWoPZMt4V38sAcE42Raf+7yfFWG5HO74JY6iEnW
gJeRk58K+avB/XLF2/j2RQZfjTYizrprT2tUMBK6e7DRWZZtk8AOcsMhUikev44IFGNbNXjP8BXC
0J3y3P7pCFT6l+saU83nRwi/H25fSA34diJtNw==

`pragma protect key_keyowner="Metrics Technologies Inc.", key_keyname="DSim", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
a/8ooC+s+6nfvfa1+oBhsvYWLJjFgp83DI1kNyOi5Am+ugPbGRmgGZudfyo6yw6Yd5gGbLm5aToQ
5G4cGF5HaXD5TU6A0ZZFMTIbzFLE76JMjjIxX8JcaJIZpSmrXqlru8l5gDINUEAmwUY3mRQnjcGJ
0Z+kMRH8iAEF+gEviPiFZSBbJeOPqivIS217kimQJX3BeNbNPQTP+GUidcRywpGMh5avxtA0kDRO
F9SoCSyTm9hr2v9hsK1IUAYQLb7n2/R+z5YNKNzt1oN4qgJH1wZfdI8if2K8+ohyOdnxrrgJOWdj
cOqr7cGqEOYfBMTIQeHVZzb7NGWVN+9B8XSUaQ==

`pragma protect key_keyowner="Atrenta", key_keyname="ATR-SG-RSA-1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=384)
`pragma protect key_block
FLPvOUNRWNW2GU+FEGmt2XWthOT5bY/31DRbol2cUmEGNF6b2XzpCosNKGx/o2n6sQvGP39KRFCs
nJu0ihe2dUGee9nEZZUcpwPjnEfXVI3yJaRVYy8iL+rm59lXq0jX4sjAPieDvv8shgAnoXLTZGlq
K+2c1JhaHt+nFi27TDrYar/+P8nP1MhocOS7BjzCvSs0foEXj92/qD+71Sm/LqGr8cjlH2qTJJ8B
ynxoH6iT+bksVA2VbtPT9o6h1kJ/zwP4wcsL9l+qSlJhd4GI11JPux26DlNyIi41WmufQcfiT0PB
r6O9+0E9lV9ODwKdjaxfZRK29rjKeq2yr0jWhMV38XKKqHAJli7MIypGRXcCo+u89H87KgYt+ebw
s3foIqCe0JKR57WzI8VD6XdNtOL8eBxK539oemx4vkE0cGYECZKYru6A2hPeZOYDD5eyWSUlQl1R
EciK49WM8HnssyRVcmE6di6bISMbVi0TZG/v98bz+9UZa8DtqMVYH0tz

`pragma protect key_keyowner="Cadence Design Systems.", key_keyname="CDS_RSA_KEY_VER_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
fphquQOeFuqByo36Gh2C1zEC1J6u9swSMbMzsKldIvLm+SZ6/hr/N8KJ/G2vBABzX6UtbVuP1ZXx
AxdftP4Aqis1B3Bs6989aQG9eo0SOHA7r6aFLtFb3qoD5Pvqw4aVNU4z4EtTpFpn/jCWD21lKROf
q5X32HRfFq1jwqod+9vIbUNRRzz5y9VHvXfacZlxDazSPmcCF4hxB1KqWqT44KmYVkDedgkgnYgb
ZGidHnTb3W7C8tSqC9ac4kNJCL429QndtddweESJNlpX+65pt9Irok9pkOodwoj0QScswOIFjhBZ
/GrzZLQcFWiD3gXRU4DazzxQnGdRH4qEIRWziw==

`pragma protect key_keyowner="Synplicity", key_keyname="SYNP15_1", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
1lUYYHPCt1BUJOvcBbgMU2GSQiqfxItz4ntieMaenjrtsE9SLwaU6xB0tBl8Atw5yP/RRNww1kX/
9uZbTz5He3r9mPVt+mGxB4N3f9BbCrQRb4USVPgKO/+vWUfMQERGklScy0+fz75WuxH74CjRUoDI
8iyssb2cUNnfDe13jIoI8gM1w4w/Pkxkmb6Mef53QMxacHAWEZeytcH3fuL/adO263D8P90U3XJv
vBXJmbjkRVi9qzjBzfMxuOy2KbZaZgR3BLzaffIfFnMwg/Rb8sGls5pQsZv5jL2wk3+Bj3OXBYdd
pDyjGoalJBzObKzd/t15kNHwY4FXYFcZLQPncw==

`pragma protect key_keyowner="Mentor Graphics Corporation", key_keyname="MGC-PREC-RSA", key_method="rsa"
`pragma protect encoding = (enctype="BASE64", line_length=76, bytes=256)
`pragma protect key_block
YRmSEzaa2WFVvMH1BwWc1TIUpVbzSEIP0VbI6n0sEgct/X4PiTfMQmK1jBVCaISIzwBxscKQwZOt
mb/nmINGg6I7ih39LSbBMtx6cdCUiyaLkPeRbqfyPpKhvnUIFmdKVvTd1dYzxeOeuDnhSVaBaAcN
3lngSg7lIbmhLIGjC29yQrBTiLArbVZi6IRGronMK51e3UrYa6GspsznhiuRcXjEb4bHKrJ2CM5Z
BUwA+E9949sQgyOagFZbLVle2ESbwBaoxcAPn2gxfRHlT0leqyLgUGDZLsfArzGzw9BTGzyEG2TR
XOrKFNYRfMXMrnGsBM7acIelY4LdAMgsKgDH/A==

`pragma protect data_method = "AES128-CBC"
`pragma protect encoding = (enctype = "BASE64", line_length = 76, bytes = 60000)
`pragma protect data_block
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
`pragma protect end_protected
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
